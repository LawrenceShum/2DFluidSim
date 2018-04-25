# pragma once

# include "KaminoQuantity.h"
# include <opencv2/opencv.hpp>

const std::string filepath = "output/frame";
const std::string particlePath = "particles/frame";

class Kamino
{
private:
    size_t nTheta;              // number of grid cells in u direction
    size_t nPhi;                // number of grid cells in v direction
    fReal gridLen;              // grid spacing (square in uv plane)
    fReal radius;               // radius of sphere
    
    /* practical condition: dt <= 5*dx / u_max */
    /* dt should be less than DT as well */
    float dt;                   // time step
    float DT;                   // frame rate @24 fps = 0.0147
    int frames;                 // number of frames to export
    fReal particleDensity;        // number of particles per unit area on the flat sphere

    std::string testPath;       // folder destination for test bgeo files
    std::string particlePath;   // folder destination for simulation bgeo files

    /* velocity initialization */
    /* u = f(phi) * g(theta) */
    /* v = l(phi) * m(theta) */
    /* coefficients are for Fourier sums representing each of the above functions */
    std::vector<fReal> fPhiCoeff;
    std::vector<fReal> gThetaCoeff;
    std::vector<fReal> lPhiCoeff;
    std::vector<fReal> mThetaCoeff;

public:
    Kamino(fReal radius = 5.0, size_t nTheta = 64, fReal particleDensity = 200.0,
        float dt = 0.005, float DT = 1.0 / 24.0, int frames = 1000,
        std::string testPath = "output/frame", std::string particlePath = "particles/frame");
    ~Kamino();

    /* run the solver */
    void run();
    /* output to test initial velocity field/flow */
    void test();
};