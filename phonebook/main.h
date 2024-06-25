#pragma once
#include "app.h"
#include "login.h"

int main() {
	loginx login;
	bool start = login.func();
	if (start) {
		appx app;
		app.start();
	}

	return 0;
}