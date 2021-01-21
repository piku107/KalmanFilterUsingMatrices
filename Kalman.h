#pragma once
#include "Kalman1D.h"

class Kalman
{
public:
	// STEP 1 PREDICT
    // Predict the next state
	MatrixXd statePrediction(MatrixXd, MatrixXd);

	// Predict state estimate uncertainty
	MatrixXd covPrediction(MatrixXd, MatrixXd, MatrixXd);

	// STEP 2 UPDATE
	// Kalman Gain calculation
	MatrixXd kalmanGain(MatrixXd, MatrixXd, MatrixXd);

	// Estimating the current state
	MatrixXd stateUpdate(MatrixXd, MatrixXd, MatrixXd, MatrixXd);

	// Update the current state estimate uncertainty
	MatrixXd covUpdate(MatrixXd, MatrixXd, MatrixXd);
};