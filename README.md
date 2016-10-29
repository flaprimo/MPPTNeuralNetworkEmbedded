# MPPTNeuralNetworkEmbedded
Bachelor's degree thesis at Università degli Studi Roma Tre with title "Design and Implementation of a MPPT algorithm for photovoltaic panels based on neural networks". Feed-Forward Multi Layer Perceptron solution for MPPT for photovoltaic panels.
More info and the thesis (in italian) on my [website](https://flavioprimo.xyz/programming-languages/design-implementation-mppt-algorithm-photovoltaic-panels-based-neural-networks/).
Complete software with testing, simulation and configurability available [here](https://github.com/flaprimo/MPPTNeuralNetwork/).

Implementation of [this software](https://github.com/flaprimo/MPPTNeuralNetwork/) for Stellaris Launchpad LM4F120H5QR by Texas Instruments.

* **neuralnet.h** - Computes a Feed-Forward Multi Layer Perceptron Neural Net for solving MPPT. It takes voltage, current and temperature of the photovoltaic panel and outputs the optimal voltage to apply to the panel in order to get the MPP.
* **uart_debug.h** - [Serial communication library](https://github.com/pradeepa-s/debug_libraries/tree/master/Stellaris_Launchpad/printf_uart) for Stellaris Launchpad
* **helper.h** - Float to string conversion library based on this [StackOverflow question](http://stackoverflow.com/questions/2302969/how-to-implement-char-ftoafloat-num-without-sprintf-library-function-i)

Libraries/Tech:
* [CMake](http://cmake.org/) - builds
* [StellarisWare](http://www.ti.com/tool/sw-lm3s/) - libraries for Stellaris Launchpad made by Texas Instruments

# Credits
Made by: [Flavio Primo](https://flavioprimo.xyz/about/)

Supervisor: [Francesco Riganti Fulginei](https://it.linkedin.com/in/francesco-riganti-fulginei-102153b/)
