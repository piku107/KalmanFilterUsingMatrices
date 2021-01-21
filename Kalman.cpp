#include "Kalman.h"

// STEP 1 PREDICT
// Predict the next state
MatrixXd Kalman::statePrediction(MatrixXd F, MatrixXd xPost)
{
	MatrixXd xPri = F * xPost;
}

// Predict estimate uncertainty
MatrixXd Kalman::covPrediction(MatrixXd F, MatrixXd pPost, MatrixXd Q)
{
	MatrixXd pPri = F * pPost * F.transpose() + Q;
	return pPri;
}

// STEP 2 UPDATE
// Kalman Gain calculation
MatrixXd Kalman::kalmanGain(MatrixXd pPri, MatrixXd R, MatrixXd H)
{
	MatrixXd S = H * pPri * H.transpose() + R;
	MatrixXd K = pPri * H.transpose() * S.inverse();
	return K;
}

// Updating the the current state using new measurements
MatrixXd Kalman::stateUpdate(MatrixXd xPri, MatrixXd z, MatrixXd K, MatrixXd H)
{
	MatrixXd xPost = xPri + K * (z - H * xPri);
	return xPost;
}

// Update the current estimate uncertainty
MatrixXd Kalman::covUpdate(MatrixXd K, MatrixXd pPri, MatrixXd H)
{
	MatrixXd pPost = (MatrixXd::Identity() - K * H) * pPri;
	return pPost;
}