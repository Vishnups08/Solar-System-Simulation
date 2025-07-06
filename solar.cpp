#include <GLUT/glut.h>
#include <cmath>
#include <cstring>
#include <cstdlib>

// State to track whether the simulation is running
bool simulationRunning = false;

// Angles for each planet and moon
float angleMercury = 0.0, angleVenus = 0.0, angleEarth = 0.0, angleMars = 0.0;
float angleJupiter = 0.0, angleSaturn = 0.0, angleUranus = 0.0, angleNeptune = 0.0;
float angleMoon = 0.0;

// Speed for planets and moon
float planetSpeed = 0.5;
float moonSpeed = 3.0;

// Function to draw text
void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// Function to draw orbit paths
void drawOrbit(float radius) {
    glColor3f(0.5, 0.5, 0.5);  // Grey orbit
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = i * M_PI / 180.0;
        glVertex3f(radius * cos(angle), 0.0, radius * sin(angle));
    }
    glEnd();
}

// Function to draw a sphere
void drawSphere(float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glutSolidSphere(radius, 50, 50);
}

// Function to draw the stars in the background
void drawStars() {
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);  // White stars
    for (int i = 0; i < 1000; i++) {
        float x = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
        float y = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
        float z = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
        glVertex3f(x, y, z);
    }
    glEnd();
}

// Function to render the welcome screen
void renderWelcomeScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set orthographic projection for 2D text
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);

    // Draw "Solar System" text in the center and larger
    glColor3f(1.0, 1.0, 0.0);// Yellow color
    drawText("Solar System", -2.5, 0.5); // Centered horizontally, slightly above center

    // Draw "Press 'S' to Start" text centered below "Solar System"
    glColor3f(1.0, 1.0, 0.0);  // Yellow color
    drawText("Press 'S' to Start", -2.5, -0.5); // Centered horizontally, below "Solar System"

    glutSwapBuffers();
}

// Function to render the solar system
void renderSolarSystem() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);

    // Move the camera back to view the scene
    gluLookAt(0.0, 15.0, 50.0,  // Camera position
              0.0, 0.0, 0.0,   // Look-at point
              0.0, 1.0, 0.0);  // Up vector

    // Draw stars
    drawStars();

    // Draw Sun
    glPushMatrix();
    drawSphere(2.0, 1.0, 1.0, 0.0);  // Yellow Sun
    drawText("Sun", -0.5, -3.0); // Label the Sun
    glPopMatrix();

    // Draw Planets
    const struct {
        float distance, radius;
        float r, g, b;
        float& angle;
        const char* name;
    } planets[] = {
        {4.0, 0.4, 0.5, 0.5, 0.5, angleMercury, "Mercury"},
        {6.0, 0.6, 0.8, 0.5, 0.2, angleVenus, "Venus"},
        {8.0, 0.7, 0.0, 0.0, 1.0, angleEarth, "Earth"},
        {10.0, 0.5, 1.0, 0.0, 0.0, angleMars, "Mars"},
        {14.0, 1.2, 0.8, 0.5, 0.2, angleJupiter, "Jupiter"},
        {18.0, 1.0, 0.5, 0.5, 0.8, angleSaturn, "Saturn"},
        {22.0, 0.8, 0.0, 1.0, 1.0, angleUranus, "Uranus"},
        {26.0, 0.7, 0.0, 0.5, 1.0, angleNeptune, "Neptune"}
    };

    for (const auto& planet : planets) {
        // Draw orbit path
        drawOrbit(planet.distance);

        glPushMatrix();
        glRotatef(planet.angle, 0.0, 1.0, 0.0);  // Orbit around Sun
        glTranslatef(planet.distance, 0.0, 0.0);  // Distance from Sun
        drawSphere(planet.radius, planet.r, planet.g, planet.b);  // Draw planet
        drawText(planet.name, -0.5, -1.0);  // Label the planet

        // Special handling for Earth to add the Moon
        if (strcmp(planet.name, "Earth") == 0) {
            glPushMatrix();
            glRotatef(angleMoon, 0.0, 1.0, 0.0);  // Moon orbit around Earth
            glTranslatef(1.5, 0.0, 0.0);  // Moon's distance from Earth
            drawSphere(0.2, 0.8, 0.8, 0.8);  // Draw Moon (grayish color)
            drawText("Moon", -0.2, -0.5);  // Label Moon
            glPopMatrix();
        }

        glPopMatrix();
    }

    glutSwapBuffers();
}

// Display callback
void display() {
    if (simulationRunning) {
        renderSolarSystem();
    } else {
        renderWelcomeScreen();
    }
}

// Timer callback
void update(int value) {
    if (simulationRunning) {
        // Increment angles for each planet
        angleMercury += planetSpeed * 4.15; if (angleMercury >= 360) angleMercury -= 360;
        angleVenus += planetSpeed * 1.62; if (angleVenus >= 360) angleVenus -= 360;
        angleEarth += planetSpeed * 1.00; if (angleEarth >= 360) angleEarth -= 360;
        angleMars += planetSpeed * 0.81; if (angleMars >= 360) angleMars -= 360;
        angleJupiter += planetSpeed * 0.43; if (angleJupiter >= 360) angleJupiter -= 360;
        angleSaturn += planetSpeed * 0.32; if (angleSaturn >= 360) angleSaturn -= 360;
        angleUranus += planetSpeed * 0.23; if (angleUranus >= 360) angleUranus -= 360;
        angleNeptune += planetSpeed * 0.18; if (angleNeptune >= 360) angleNeptune -= 360;

        // Update Moon angle
        angleMoon += moonSpeed; 
        if (angleMoon >= 360) angleMoon -= 360;

        glutPostRedisplay();
    }
    glutTimerFunc(16, update, 0);  // Call again after 16ms (~60fps)
}

// Keyboard callback
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) exit(0);        // ESC to exit
    if (key == 's' || key == 'S') simulationRunning = true;  // Start simulation
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Solar System");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}