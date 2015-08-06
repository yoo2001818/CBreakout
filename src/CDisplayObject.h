#ifndef SRC_CDISPLAYOBJECT_H_
#define SRC_CDISPLAYOBJECT_H_

#include <SDL2/SDL.h>
class CDisplayContainer;
class CStage;

class CDisplayObject {
public:
	CDisplayObject();
	virtual ~CDisplayObject();

	SDL_Rect rect;

	float x;
	float y;

	CStage * stage;
	CDisplayContainer * parent;

	bool isAlive;

	virtual void Event(SDL_Event * event) {
	}
	virtual void Update(int delta) {
	  rect.x = (int)x;
	  rect.y = (int)y;
	}
	virtual void Render() {
	  rect.x = (int)x;
	  rect.y = (int)y;
	}

	virtual void OnAdd() {

	}
	virtual void OnRemove() {

	}

	virtual SDL_Point GlobalToLocal(SDL_Point point);
	virtual SDL_Point LocalToGlobal(SDL_Point point);
	bool HitTestRect(SDL_Rect rect);
	bool HitTestPoint(SDL_Point point);
};

#endif /* SRC_CDISPLAYOBJECT_H_ */
