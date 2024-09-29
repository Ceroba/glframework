#pragma once
#include "engine/app.h"

class programe : public App {
public:
	void setup() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 0);
		//glfwWindowHint(GLFW_ALPHA_BITS, 8);

		win = glfwCreateWindow(1000, 1000, "0", 0, 0);
		glfwMakeContextCurrent(win);
		gladLoadGL();
		vx::init();
		rend.creat(0, 32000);
		rend.updatecontex({ 1000, 1000 });
		inputhandler.win = win;
	}
	void Run() {
		setup();
		MainLoop();
	}
	void MainLoop() {
		float currentt = glfwGetTime();
		float lastt = currentt;
		while (!glfwWindowShouldClose(win))
		{
			currentt = glfwGetTime();
			if ((currentt - lastt) >= (1 / 60.f)) {
				glfwSetWindowTitle(win, std::to_string((currentt - lastt) * 1000).c_str());

				auto s = inputhandler.GetJoystickState(GLFW_JOYSTICK_1);

				rend.clear({ 0, 0, 0, 1 });

				if (s.pres)
				{
					if (s.isgpad)
					{
						//rend.rendertext({ 0, 20 }, (std::string("n of axes:") + std::to_string(s.n_axes) + "\n" + "n of buttons:" + std::to_string(s.n_buttons)).c_str(), f, { 255, 255, 255, 255 }, 0.5, 4, 3, 0);
						rend.rendercircle({ 333 + s.state.axes[GLFW_GAMEPAD_AXIS_LEFT_X] * 50, 600 + s.state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y] * 50, 60 }, { 255, 255, 255, s.state.buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB] ? 128 : 255});
						rend.rendercircle({ 667 + s.state.axes[GLFW_GAMEPAD_AXIS_RIGHT_X] * 50, 600 + s.state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y] * 50, 60 }, { 255, 255, 255, s.state.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB] ? 128 : 255 });
						//rend.renderrectangle({ 100, 100 + lt * 25, 200, 50 }, { 255, 255, 255, 255 });
						//rend.renderrectangle({ 700, 100 + rt * 25, 200, 50 }, { 255, 255, 255, 255 });
						//rend.renderrectangle({ 100, 150 , 200, 50 }, { 255, 255, 255, _buttons[4] ? 128 : 255 });
						//rend.renderrectangle({ 700, 150 , 200, 50 }, { 255, 255, 255, _buttons[5] ? 128 : 255 });
						//rend.rendercircle({ 750, 325, 20 }, { 255, 255, 255, _buttons[0] ? 128 : 255 });
						//rend.rendercircle({ 800, 275, 20 }, { 255, 255, 255, _buttons[1] ? 128 : 255 });
						//rend.rendercircle({ 700, 275, 20 }, { 255, 255, 255, _buttons[2] ? 128 : 255 });
						//rend.rendercircle({ 750, 225, 20 }, { 255, 255, 255, _buttons[3] ? 128 : 255 });

						//rend.renderrectangle({ 150, 325, 30, 30 }, { 255, 255, 255, _buttons[12] ? 128 : 255 });
						//rend.renderrectangle({ 200, 275, 30, 30 }, { 255, 255, 255, _buttons[11] ? 128 : 255 });
						//rend.renderrectangle({ 100, 275, 30, 30 }, { 255, 255, 255, _buttons[13] ? 128 : 255 });
						//rend.renderrectangle({ 150, 225, 30, 30 }, { 255, 255, 255, _buttons[10] ? 128 : 255 });
					}
					/*for (int i = 0; i < 14; i++) {
						rend.renderrectangle({ 50 * i, 225, 20, 20 }, { 255, 255, 255, _buttons[i] ? 128 : 255 });

					}*/
					//
				}


				rend.flush();

				glfwSwapBuffers(win);
				glfwPollEvents();
				lastt = currentt;
			}
		}
	}
	vx::renderer rend;
	GLFWwindow* win;
};

