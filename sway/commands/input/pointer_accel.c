#include <stdlib.h>
#include <string.h>
#include "sway/config.h"
#include "sway/commands.h"
#include "sway/input/input-manager.h"

struct cmd_results *input_cmd_pointer_accel(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "pointer_accel", EXPECTED_AT_LEAST, 1))) {
		return error;
	}
	struct input_config *ic = config->handler_context.input_config;
	if (!ic) {
		return cmd_results_new(CMD_FAILURE,
			"pointer_accel", "No input device defined.");
	}

	float pointer_accel = atof(argv[0]);
	if (pointer_accel < -1 || pointer_accel > 1) {
		return cmd_results_new(CMD_INVALID, "pointer_accel",
			"Input out of range [-1, 1]");
	}
	ic->pointer_accel = pointer_accel;

	return cmd_results_new(CMD_SUCCESS, NULL, NULL);
}
