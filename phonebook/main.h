#pragma once
#include "app.h"
#include "login.h"

int main() {
	loginx login;
	int start = login.func();
	if (start==1) {
		appx app;
		app.start();
	}
	else if (start == 2) {
		appx app;
		app.reset();
	}

	return 0;
}