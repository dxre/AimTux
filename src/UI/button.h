#ifndef __BUTTON_H_
#define __BUTTON_H_

#include "component.h"
#include "../settings.h"

class Button : public Component
{
public:
	
	std::function<void()> OnClickedEvent;
	
	std::string text = "button";
	
	bool clickStarted = false;
	
	void Event_OnMouseClickEnd ()
	{
		if (OnClickedEvent != NULL && clickStarted)
		{
			OnClickedEvent ();
			clickStarted = false;
		}
	}
	
	void Event_OnMouseClickStart ()
	{
		clickStarted = true;
	}
	
	void Event_OnMouseLeave ()
	{
		clickStarted = false;
	}
	
	Button (std::string text, Vector2D position, Vector2D size)
	{
		this->position = position;
		this->size = size;
		this->text = text;
		
		onMouseClickEndEvent	= MFUNC (&Button::Event_OnMouseClickEnd, this);
		onMouseClickStartEvent	= MFUNC (&Button::Event_OnMouseClickStart, this);
		onMouseLeaveEvent		= MFUNC (&Button::Event_OnMouseLeave, this);
	}
	
	void Draw ()
	{
		Color color = isHovered ? Color (150, 100, 100) : Color (200, 100, 100, 255);
		Clear (color);
		
		DrawCenteredString (text, normal_font, Color (255, 255, 255, 255), LOC (size.x / 2, size.y / 2));
	}
};

class OutlinedButton : public Button
{
public:
	OutlinedButton (std::string text, Vector2D position, Vector2D size)
						: Button (text, position, size) { }
	
	void Draw ()
	{
		Clear (Color (40, 40, 40, 150));
		
		if (isHovered)
		{
			DrawRectangle (LOC (0, 0), size, Settings::UI::mainColor);
		}
		
		DrawCenteredString (text, normal_font, Color (255, 255, 255, 255), LOC (size.x / 2, size.y / 2));
	}
};



#endif