#include <stdio.h>
#include <stdlib.h>

main()
{
    long nb_planes     = 7;
    long nb_sat_plane  = 11;
	// Rosetta: nb_planes    = 8;
    // Rosetta:  nb_sat_plane = 6;
    
	long nb_satellites = nb_planes * nb_sat_plane;
    long i, j;

    FILE *constel_file = fopen("constel_file.xml", "w");

    fprintf(constel_file, "<?xml version=\"1.0\"?>\n");

    // Write SatOrb project header
    fprintf(constel_file, "<SatOrb>\n");
    fprintf(constel_file, "<Project Name=\"const_2sat\" Version=\"2\">\n");
    fprintf(constel_file, "<sun blnSunImage=\"True\" blnSunTrace=\"True\" />\n");
    fprintf(constel_file, "<earth EarthImage=\"Earth from space\" ECI=\"B1950\" Attitude=\"True\" />\n");
    fprintf(constel_file, "<time SimulationStart=\"24497\" SimulationTime=\"24497\" />\n");
    fprintf(constel_file, "</Project>\n");

    // Write satellites section
    fprintf(constel_file, "<Satellites>\n");

    for (i = 0; i < nb_satellites; i++) // Loop on satellites
    {
        fprintf(constel_file, "<satellite Name=\"CONS_1_%d\" IDSat=\"%d\" IDCons=\"0\">\n", i, i);
        fprintf(constel_file, "<axes>\n");
        fprintf(constel_file, "<primary Axis=\"-z\" Dir=\"nadir\" ID=\"-1\" />\n");
        fprintf(constel_file, "<secondary Axis=\"x\" Dir=\"velocity\" ID=\"-1\" />\n");
        fprintf(constel_file, "</axes>\n");
        fprintf(constel_file, "<propagator Name=\"Kepler\" />\n");
        fprintf(constel_file,
                "<graphics BackTrackSize=\"0\" ForwardTrackSize=\"0\" blnFootprint=\"-1\" Color=\"16777215\" />\n");
        fprintf(constel_file, "</satellite>\n");
    }
    fprintf(constel_file, "</Satellites>\n");

    // Write constellation and various parameters (not used here)
    fprintf(constel_file, "<GroundStations />\n");
    fprintf(constel_file, "<Constellations>\n");
    fprintf(constel_file, "<constellation Name=\"CONS_1\" IDCons=\"0\" />\n");
    fprintf(constel_file, "</Constellations>\n");
    fprintf(constel_file, "<Maneuvers />\n");
    fprintf(constel_file, "<Links />\n");
    fprintf(constel_file, "<Antennas />\n");
    fprintf(constel_file, "<Accessories />\n");

    // Write satellite orbits
    fprintf(constel_file, "<Orbits>\n");
    for (i = 0; i < nb_planes; i++) // Loop on planes
    {
        for (j = 0; j < nb_sat_plane; j++)
        {
            fprintf(constel_file, "<orbit IDSat=\"%d\">\n", i * nb_sat_plane + j);
            fprintf(constel_file,
                    "<aei altitude=\"7158.137\" elevation=\"1E-07\" inclinaison=\"90.0\" />\n"); // Altitude
					
            // Or Rosetta: fprintf(constel_file, "<aei altitude=\"1414.0\" elevation=\"1E-07\" inclinaison=\"52.0\" />\n"); // Altitude
            fprintf(constel_file, "<epoch value=\"24497\" />\n");
            fprintf(constel_file, "<derivations>\n");
            fprintf(constel_file, "<first value=\"0\" />\n");
            fprintf(constel_file, "<second value=\"0\" />\n");
            fprintf(constel_file, "</derivations>\n");
            fprintf(constel_file, "<perigee value=\"0\" />\n");
            fprintf(constel_file, "<anomaly value=\"%lf\" />\n",
                    (i % 2) * (180.0 / nb_sat_plane) + j * (360.0 / nb_sat_plane)); // Anomaly
            fprintf(constel_file, "<raan value=\"%lf\" />\n", i * 27.8);            // Right Ascending Node
            fprintf(constel_file, "<BStar value=\"0\" />\n");
            fprintf(constel_file, "<CoordSyst value=\"\" />\n");
            fprintf(constel_file, "</orbit>\n");
        }
    }

    // Write SatOrb project footer
    fprintf(constel_file, "</Orbits>\n");
    fprintf(constel_file, "</SatOrb>\n");
}