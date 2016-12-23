#include <stdio.h>

#include "error.h"

void display_error(error_level level, int code)
{
	char *error_level = ((level) ? "WARNING" : "ERROR");
	fprintf(stderr, "%s %d: %s\n",
			error_level,
			code,
			get_error_message(code));
}

const char *get_error_message(int code)
{
	switch (code) {
		//Generic errors
		case 1:
			return "NULL file pointer while checking type.";
		case 3:
			return "File type not supported.";
		case 4:
			return "Could not open input file.";

			//JPEG related errors
		case 100:
			return "Failed to open JPEG file while trying to get markers";
		case 101:
			return "Failed to open input JPEG file while optimizing";
		case 102:
			return "Failed to open output JPEG file while optimizing";
		case 103:
			return "Failed to open JPEG file while compressing";
		case 104:
			return "Failed to open JPEG file while decompressing";

			//PNG related errors
		case 200:
			return "Failed to load PNG file.";
		case 201:
			return "Error while optimizing PNG.";
		case 203:
			return "Error while writing output PNG file.";

		default:
			return "Unrecognized error.";
	}
}