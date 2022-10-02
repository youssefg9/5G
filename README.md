# 5g fronthaul sim
 communication blocks simulation and ethernet packet generation & analysis
 
## communication blocks file
it contains communication blocks with the AWGN channel effect . where the awgn affects the IQ symbols generated from the modulation class and outputted in the testMod variable.
For future work on this simulation , i'll try to make the modulation class generalised to output QAM symbols ,and for the AWGN ill try showing the effect not only on the phase and amplitude of the symbols affected by the channel but also on the bits in the symbol (where a modulated symbol can be affected by a 0 , 1 or x bit flips) and by this I’ll be able to test the output of the AWGN channel into the decoder,demapper,descrambler ,demodulator and the receiver cyclic prefix 

We input test data in main method variable:string symbolStream


## ethernet packet generation
found wihin the file a text file called input_config containing the adjustable configurations for this ethernet frame simulation, where the data inputs must be put in the same sequence put in the text file to output correctly , and a user can change the values after the "=" sign in each line and write comments after the "#" sign.
