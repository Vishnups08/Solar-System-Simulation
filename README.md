# Solar System Simulation

A 3D OpenGL-based solar system simulation that demonstrates the orbital mechanics of planets around the Sun, including Earth's Moon. This project provides an interactive visualization of our solar system with realistic relative speeds and distances.

## 🌟 Features

- **3D Solar System Visualization**: Complete solar system with all 8 planets
- **Realistic Orbital Mechanics**: Planets orbit at different speeds based on their distance from the Sun
- **Interactive Controls**: Start/stop simulation and exit functionality
- **Welcome Screen**: Clean interface with instructions
- **Planet Labels**: Each celestial body is clearly labeled
- **Starfield Background**: Randomly generated stars for immersive experience
- **Moon System**: Earth's moon orbits around Earth
- **Smooth Animation**: 60 FPS animation for fluid movement

## 🪐 Celestial Bodies Included

- **Sun** (Yellow) - Central star
- **Mercury** (Gray) - Closest to the Sun
- **Venus** (Orange) - Second planet
- **Earth** (Blue) - Our home planet with Moon
- **Mars** (Red) - The red planet
- **Jupiter** (Orange) - Largest planet
- **Saturn** (Purple) - Ringed planet
- **Uranus** (Cyan) - Ice giant
- **Neptune** (Blue) - Farthest planet
- **Moon** (Gray) - Earth's natural satellite

## 🛠️ Prerequisites

Before running this project, you need to have the following installed:

### macOS
```bash
# Install Homebrew (if not already installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install freeglut
brew install freeglut
```

### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install freeglut3-dev
```

### Windows
- Install MinGW or Visual Studio
- Install freeglut development libraries

## 🚀 Installation & Compilation

1. **Clone the repository** (when you upload to GitHub):
   ```bash
   git clone https://github.com/yourusername/solar-system-simulation.git
   cd solar-system-simulation
   ```

2. **Compile the project**:

   **macOS:**
   ```bash
   g++ solar.cpp -o solar -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION
   ```

   **Linux:**
   ```bash
   g++ solar.cpp -o solar -lglut -lGLU -lGL
   ```

   **Windows (MinGW):**
   ```bash
   g++ solar.cpp -o solar.exe -lopengl32 -lfreeglut -lglu32
   ```

## 🎮 Usage

1. **Run the simulation**:
   ```bash
   ./solar
   ```

2. **Controls**:
   - **S** - Start the solar system simulation
   - **ESC** - Exit the program

## 🎯 How It Works

### Welcome Screen
- Displays "Solar System" title
- Shows "Press 'S' to Start" instruction
- Clean, centered interface

### Simulation Mode
- **Camera Position**: Positioned to view the entire solar system
- **Orbital Speeds**: Each planet moves at a different speed based on its distance from the Sun
- **3D Perspective**: Uses perspective projection for realistic depth
- **Real-time Animation**: Continuous 60 FPS updates

### Technical Implementation
- **OpenGL Fixed Function Pipeline**: Uses traditional OpenGL for rendering
- **Matrix Transformations**: Handles rotations and translations for orbital mechanics
- **Depth Testing**: Ensures proper 3D rendering
- **Double Buffering**: Smooth animation without flickering

## 📁 Project Structure

```
solar-system-simulation/
├── solar.cpp          # Main source code
├── README.md          # This file
└── .gitignore         # Git ignore file (optional)
```

## 🎓 Learning Objectives

This project demonstrates:
- OpenGL programming fundamentals
- 3D graphics and transformations
- Real-time animation techniques
- Event-driven programming with GLUT
- Mathematical concepts in orbital mechanics

## 📄 License

This project is open source and available under the [MIT License](LICENSE).


**Enjoy exploring the solar system! 🌌** 