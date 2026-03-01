int strStr(char* haystack, char* needle) {
	int progress = 0;
	char* sp = haystack;

	while (*sp != '\0') {
		if (*sp == needle[progress]) {
			progress++;

			if (needle[progress] == '\0') {
			return sp - haystack - progress + 1;

			}
		} else {
			sp -= progress;
			progress = 0;
		}
		sp++;
	}
	return -1;
}

