# Entropy calculator and random number generator
# Christiane Kotero
# The goal of this lab was to create a truly "random" random number generator


I generated random numbers by first seeding a key using the C library function clock(). I took the nano seconds of # the time. I then bit shifted this number by one digit left.
I saved the bit shifted number to a temporary variable and XOR's it with the original time. I then took the least # # most significant eight bits of the resultant number to be
the character generated.

In order to test my entropy and random number generator I first generated three different files using my random # # # number generator. One was 4 megabytes, one was 8 megabytes and one was 9.
The entropy of the first was 7.9988073, the second was 7.998987, and the thirds was 7.998581.
This means that as the file size grew larger between the first and the second so did the entropy. This makes sense # due to the way Entropy is calculated.
If the number of possible random variables is larger, the probability of each grows smaller making the prob*log2(1/prob) larger. This is then summed up into the entropy.

I then tested three different file types, an image file (7.984244), a gif(7.925690) and an mp3 file(7.821666). The image file was surprisingly had the largest entropy.
The gif came in second and lastly the mp3 was the smallest.
