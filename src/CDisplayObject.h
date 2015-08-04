#ifndef SRC_CDISPLAYOBJECT_H_
#define SRC_CDISPLAYOBJECT_H_

#include <SDL2/SDL.h>
class CDisplayContainer;

class CDisplayObject {
public:
	CDisplayObject();
	virtual ~CDisplayObject();

	SDL_Rect rect;

	// CStage * stage;
	CDisplayContainer * parent;

	virtual void Event(SDL_Event * event) {
	}
	virtual void Update(int delta) {
	}
	virtual void Render() {
	}

	SDL_Point GlobalToLocal(SDL_Point point);
	SDL_Point LocalToGlobal(SDL_Point point);
	bool HitTestRect(SDL_Rect rect);
	bool HitTestPoint(SDL_Point rect);
};

#endif /* SRC_CDISPLAYOBJECT_H_ */
