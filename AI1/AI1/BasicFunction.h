#pragma once
#include"SFML\Graphics.hpp"

static struct Functions
{
	// Returns the length of a Vector
	static float Length(sf::Vector2f v1)
	{
		float m_VectorLength = sqrt(pow(v1.x, 2) + pow(v1.y, 2));
		return m_VectorLength;
	}

	// Gets the normal of a Vector
	static sf::Vector2f Normalise(sf::Vector2f v1)
	{
		float m_Length = Length(v1);

		if (m_Length > 0)
		{
			sf::Vector2f m_normVector = sf::Vector2f(v1.x / m_Length, v1.y / m_Length);
			return m_normVector;
		}
		else
		{
			return sf::Vector2f(0, 0);
		}
	}

	// Gets the Orientation of the sprite
	static float GetOrientation(float m_Orientation, sf::Vector2f m_Velocity)
	{
		float m_rotation = m_Orientation;
		if (Length(m_Velocity) > 0)
		{
			m_rotation = atan2f(m_Velocity.x, -m_Velocity.y);
			m_rotation = RadiansToDegrees(m_rotation);
		}
		return m_rotation;
	}

	// Sets the Velocity
	static sf::Vector2f setVelocity(float m_Orientation)
	{
		sf::Vector2f m_tempVel;
		m_tempVel.x = sin(m_Orientation);
		m_tempVel.y = -cos(m_Orientation);

		return m_tempVel;

	}

	// Converts the Radians to Degrees.
	static float RadiansToDegrees(float m_Radian)
	{
		float m_degree = m_Radian*(180 / 3.14);
		return m_degree;
	}

	static void Wander(float & time, sf::Vector2f& target, sf::Vector2f& Position, sf::Vector2f& Velocity, float& radius, float& distance, float& orientation, sf::Sprite& obj)
	{
		time += 1.0f / 60.0f;

		if (time >= 0.8f)
		{
			time = 0.0;
		}

		if (time == 0.0f)
		{
			sf::Vector2f direction = Normalise(Velocity);
			sf::Vector2f point = direction*distance;

			point += Position;
			float angle = ((rand() % 361)*3.14159 / 180);


			float x = radius*sin(angle) + point.x;
			float y = radius*cos(angle) + point.y;

			point = sf::Vector2f(x, y);
			target = point;

		}
		Seek(target, Position, Velocity, orientation, obj);
	}

	static void Seek(sf::Vector2f&  tar, sf::Vector2f& Position, sf::Vector2f& Velocity, float& orientation, sf::Sprite& obj)
	{
		Velocity = tar - Position;
		Velocity = Normalise(Velocity);
		Velocity = Velocity * 2.0f;
		orientation = GetOrientation(orientation, Velocity);
		obj.setRotation(orientation);
	}

	static void Flee(sf::Vector2f&  tar, sf::Vector2f& Position, sf::Vector2f& Velocity, float& orientation, sf::Sprite& obj)
	{
		Velocity = Position - tar;
		Velocity = Normalise(Velocity);
		Velocity = Velocity * 3.0f;
		orientation = GetOrientation(orientation, Velocity);
		obj.setRotation(orientation);
	}

};