#include <math.h>

static const int INPUT_LENGTH = 3;
static const int HIDDEN_LAYER_ROW_LENGTH = 3;
static const int HIDDEN_LAYER_COLUMN_LENGTH = 25;
static const int OUTPUT_LAYER_ROW_LENGTH = 25;


// NN CONFIGURATION
static const float MIN_INPUT[] = {750.5, 2.838927, 263};
static const float MAX_INPUT[] = {1578.8, 569.4137, 363};
static const float MIN_OUTPUT = 782.16;
static const float MAX_OUTPUT = 1403.6;

// HIDDEN LAYER
static const float HIDDEN_LAYER_WEIGHTS[] = {-4.162388, 0.730794, -2.431392, -4.896474, -0.328038, -2.967811, 1.491192,
                              -7.031680, 0.601389, 0.861134, 0.387004, 0.396748, 1.329492, -6.544066, 0.597795, -0.987176, -0.418131,
                              -0.432930, -2.305198, 3.389106, -1.554975, -0.051860, -6.302748, -0.308038, 5.260182, 0.583164, 3.266499,
                              -0.055235, -6.267354, -0.362831, 0.406702, 1.341032, 0.324966, 1.486634, -3.847890, 0.911256, -0.636496,
                              1.644910, -0.392827, 3.083439, -1.123031, 2.217883, 4.447189, -0.249650, 2.633869, 3.157065, -1.154619,
                              2.283502, 0.841558, 0.743843, 0.328180, 0.585216, -1.517525, 0.361929, 0.370214, -1.098692, 0.235458,
                              -2.146381, 3.422277, -1.429814, -0.591178, -1.215725, 0.192546, 0.045723, 0.039730, -0.155519, -0.735572,
                              -0.044603, -0.297243, -0.597163, -1.144104, 0.210976, -1.247404, -0.365307, -0.533001};
static const float HIDDEN_LAYER_BIAS[] = {3.482459, 3.462489, -8.320638, -0.311914, -8.147101, 0.025243, 4.466108, -7.258114,
                                 -3.622175, -7.111324, 1.610289, -3.278108, 0.959782, -2.365794, -3.429868, -2.415060, 0.899197, -1.038448,
                                 -1.634513, 4.398274, -1.716122, -0.349988, 0.736048, -1.690931, 0.868819};

// OUTPUT LAYER
static const float OUTPUT_LAYER_WEIGHTS[] = {1.926091, 7.352876, -3.006100, 4.036904, 8.274290, 3.102197, 4.954952, -7.802333,
                                    3.583243, 5.224246, -0.214347, 0.176114, 3.282575, 1.813378, 5.282540, -1.647750, -0.456200, 6.356190,
                                    -11.786261, -6.196810, 1.649847, 5.417224, -4.702090, -1.643533, 3.414399};
static const float OUTPUT_LAYER_BIAS = -0.404523;

float sigmoid(float x)
{
	return 2 / (1 + expf(-2 * x)) - 1;
}

float sigmoidInterpolated(float x)
{
	float sign_flag = 1;
	float out = 0;

	const float p1 = -0.3026;
	const float p2 = 1.082;
	const float p3 = -0.004793;

	const float v1 = -0.255;
	const float v2 = 0.9275;
	const float v3 = 0.08785;

	const float r1 = -0.07061;
	const float r2 = 0.3573;
	const float r3 = 0.532;

	const float g1 = -0.01523;
	const float g2 = 0.1009;
	const float g3 = 0.8294;

	const float h1 = -0.003117;
	const float h2 = 0.02563;
	const float h3 = 0.9467;

	if (x < 0) {
		x = -x;
		sign_flag = -1;
	}
	if (x < 0.8) {
		out = p1 * x * x + p2 * x + p3;
	}
	if ((x >= 0.8) & (x < 1.6)) {
		out = v1 * x * x + v2 * x + v3;
	}
	if ((x >= 1.6) & (x < 2.4)) {
		out = r1 * x * x + r2 * x + r3;
	}
	if ((x >= 2.4) & (x < 3.2)) {
		out = g1 * x * x + g2 * x + g3;
	}
	if ((x >= 3.2) & (x < 4)) {
		out = h1 * x * x + h2 * x + h3;
	}
	if (x >= 4) {
		out = 1;
	}

	return out * sign_flag;
}

/*
 * Compute the neural network
 */
float computeNN(float input[])
{
	int i, j;

	// INPUT NORMALIZATION
	for (i = 0; i < INPUT_LENGTH; i++)
		input[i] = 2 * (input[i] - MIN_INPUT[i]) / (MAX_INPUT[i] - MIN_INPUT[i]) - 1;

	// COMPUTE HIDDEN LAYER
	float outputHiddenLayer[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (i = 0; i < HIDDEN_LAYER_COLUMN_LENGTH; i++) {
		// compute weighted sum
		for (int j = 0; j < HIDDEN_LAYER_ROW_LENGTH; j++)
			outputHiddenLayer[i] += input[j]
					* HIDDEN_LAYER_WEIGHTS[HIDDEN_LAYER_ROW_LENGTH * i + j];

		// add bias and apply the activation function
		outputHiddenLayer[i] = sigmoidInterpolated(outputHiddenLayer[i] + HIDDEN_LAYER_BIAS[i]);
	}

	// COMPUTE OUTPUT
	// add bias
	float output = OUTPUT_LAYER_BIAS;

	// compute weighted sum
	for (j = 0; j < OUTPUT_LAYER_ROW_LENGTH; j++)
		output += outputHiddenLayer[j] * OUTPUT_LAYER_WEIGHTS[j];

	// OUTPUT NORMALIZATION
	return (MAX_OUTPUT - MIN_OUTPUT) * (output + 1) / 2 + MIN_OUTPUT;
}
