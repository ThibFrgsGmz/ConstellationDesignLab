# ConstellationDesignLab

The objective of this workshop, which was held several years ago, was to present the main design methods for single and multiple visibility satellite constellations. These satellite constellations can be used in a variety of communication and navigation systems to provide services such as data transmission or the provision of precise navigation positions.

In this workshop, special attention was given to the design of polar-orbiting constellations, a topic that was studied in depth by D.C. Beste in a paper published in 1978.

To facilitate the analysis and optimization of satellite constellations, the SatOrb software was used. This software, which was jointly developed by ISAE and TÜM, allows to analyze the visibility periods of satellites, to obtain visibility statistics and to find the optimal number and distribution of satellites to achieve specific objectives.

SatOrb uses an XML format to describe satellite constellations, which facilitates data manipulation and analysis. This repository also contains a C program that generates an XML file describing the parameters of each satellite in the constellation. This XML file can be read by the SatOrb software, allowing a coverage analysis to be performed to evaluate the performance of the constellation and deduce the strengths and weaknesses of its design.


https://ieeexplore.ieee.org/document/4101990