#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	Font* font, string text,
	Color idleColor, Color hoverColor, Color activeColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(Vector2f(x, y));
	this->shape.setSize(Vector2f(width, height));

	this->font = font;
	this->text.setString(text);
	this->text.setFont(*this->font);
	this->text.setFillColor(Color::White);
	this->text.setCharacterSize(24);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = Color::Transparent;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
	
}

//Accesors

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}

//Functions
void Button::update(const Vector2f mousePos)
{
	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;

	default:
		this->shape.setFillColor(Color::Red);
		break;
	}
}

void Button::render(RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
