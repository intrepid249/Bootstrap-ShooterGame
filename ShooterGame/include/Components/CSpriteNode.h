#pragma once
#include <Components\CComponent.h>

namespace aie {
	class Texture;
}

class GameEntity;

/**
*Inherits from Node to store a location matrix and Node's methods
*Implements additional functionality to allow storage and rendering
of sprites*/
class CSpriteNode : public CComponent {
public:
	CSpriteNode();
	CSpriteNode(aie::Texture *m_tex);
	~CSpriteNode();

	/** Method that allows drawing the sprite to the screen*/
	virtual void render(aie::Renderer2D * renderer);

	/** Set the size of the Sprite Node*/
	void setSize(const Vector2<float> &size);
	/** Get the size of the Sprite Node*/
	Vector2<float>& getSize();

	/** Scale the image by given amount*/
	void scale(Vector2<float> _scale);
	/** Get the amount of scaling applied*/
	Vector2<float> getScale();
	
	/** Set the rendering offset of the Sprite Node - transformation anchor*/
	void setOrigin(const Vector2<float> &origin);
	/** Get the rendering offset of the Sprite Node - transformation anchor*/
	Vector2<float>& getOrigin();

	/** Return the texture associated with the instance the function is called from*/
	virtual aie::Texture* getTexture();

	/** Set the parent entity that uses this component*/
	void setParent(GameEntity* _parent);
	/** Get the parent entity using this component*/
	GameEntity *getParent();

	/** Increment the rotation by an amount*/
	void rotate(float _amt);
	/** Set the rotation angle*/
	void setRotate(float _angle);
	/** Get the current angle of rotation*/
	float getRotation();

protected:
	aie::Texture *m_sprite;
	Vector2<float> m_size, m_scale;
	Vector2<float> m_origin = Vector2<float>(0.5f, 0.5f);		// Transformation anchor - defaults to centre of image
	GameEntity* m_parent;
	float m_rotation;
};

