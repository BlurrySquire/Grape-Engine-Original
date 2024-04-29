#pragma once

namespace GRAPE {
	enum class EventType {
		NONE = 0,
		WINDOW_CLOSE = 1,
		KEYBOARD_KEY_DOWN = 2,
		KEYBOARD_KEY_UP = 3,
		MOUSE_MOVE = 4,
		MOUSE_DOWN = 5,
	};

	struct Event {
		EventType type;
	};
}