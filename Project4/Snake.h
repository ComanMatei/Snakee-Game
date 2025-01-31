#pragma once

#include <list>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Snake : public sf::Drawable
{
public:
    Snake();
    ~Snake();

    void Init(const sf::Texture& texture);
    void Move(const sf::Vector2f& direction);
    bool IsOn(const sf::Sprite& other) const;
    void Grow(const sf::Vector2f& direction);
    bool IsSelfIntersecting() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    std::list<sf::Sprite> snakeBody;
    std::list<sf::Sprite>::iterator snakeHead;
    std::list<sf::Sprite>::iterator snakeTail;
};