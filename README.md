# Adventure Quest, Embedded

## Reasoning

    14:00 <+bentglasstube> it's like adventure quest for kickstarters
    14:05 <+stevenf> why isn't adventure quest a physical object yet?
    14:06 <+bentglasstube> because string manipulation in C is terrible
    14:06 <+stevenf> hahaha
    14:06 <+stevenf> good answer

## Installation

    make
    make install

## Thoughts

String manipulation in C _is_ terrible.  This code is ridiculously brittle.
Large chunks of it were written by a perl script.  Changing the data is not for
the feint of heart.

## Bugs

The name generator is non-halting with very low probability.  If aq seems to
hang forever, go buy a lottery ticket.

## Copyright and License

Copyright 2014 Alan Berndt

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
