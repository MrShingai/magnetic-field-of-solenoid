Magnetic Field of a Finite Solenoid – Simulation & Plot (C + Gnuplot)

Author: Tshepo Shingai Kgangetsile
Neptun Code: QA9158
University of Debrecen – Mechatronics Department

📌 Overview

This project calculates and visualizes the magnetic field along the axis of a finite solenoid using the analytical expression derived from the Biot–Savart law.

The program:

Computes the magnetic field 
B(z) from z = 0 to z = L

Saves the values in data.txt

Automatically generates a Gnuplot plotting script

Displays the graph for analysis

The resulting plot shows the strong central field of the solenoid and the expected decrease near the ends.

📐 Physics Background

The magnetic field along the axis of a finite solenoid with
N turns, length L, radius R, and current I is given by:

B(z) = (μ₀ N I / 2L) · [ z / √(R² + z²) + (L − z) / √(R² + (L − z)² ) ]

This is the formula implemented inside the function magnetic_field().

The Gnuplot-generated graph displays:

x-axis: z (position along solenoid)
y-axis: B(z) (magnetic field strength in Tesla)
A smooth field curve:
Highest near the center
Decreasing symmetrically toward both ends

🛠 Requirements
1. Install Gnuplot

Download (Windows):

https://sourceforge.net/projects/gnuplot/files/gnuplot/6.0.3/gp603-win64-mingw.exe/download

During installation:
✔ Tick “Add to PATH”

2. Compile the Program

Using GCC:

gcc solenoid.c -o solenoid -lm

3. Run
./solenoid
The program will produce:

data.txt
plot_script.gp

A Gnuplot window with the graph

📁 Folder Structure
/
├── solenoid.c
├── data.txt
├── plot_script.gp
├── README.md
└── LICENSE

📝 Example Output
z (m)        B(z) (T)
-----------------------------
0.0000       1.234e-03
0.0100       1.567e-03
...

🎯 Purpose

This project demonstrates the magnetic field distribution of a finite solenoid and serves as a small physics simulation tool for students and educators.

🔧 License

This project is released under the MIT License.

📬 Contact

Tshepo Shingai Kgangetsile
Neptun: QA9158
email:shangitsk@gmail.com

