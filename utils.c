void one_space(char *str) {
	/** ... to Rule Them All!
	 * Converts str to words separated by one space.
	 * Modifies str in-place.
	 */
	int i, g;
	for(i = g = 1; str[i]; i++) {
		// if isspace and previous isspace then pass (De Morgan's Laws)
		if(!isspace(str[i]) || !isspace(str[i-1])) {
			str[g++] = str[i];
		}
	}
	str[g] = '\0';
}
