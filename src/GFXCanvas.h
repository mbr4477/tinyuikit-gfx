#ifndef _UI_GFXCANVAS_H_
#define _UI_GFXCANVAS_H_
#include "Adafruit_GFX.h"
#include "ui.h"

namespace ui
{
    class GFXCanvas : public Canvas
    {
    public:
        enum ColorOrder
        {
            RGB,
            BGR
        };
        GFXCanvas(Adafruit_GFX &gfx, ColorOrder order);
        void clearRect(Box rect);
        void fillRect(Box rect, Color fill);
        void strokeRect(Box rect, Color border);
        void addText(std::string text, unsigned int x, unsigned int y, Color color);
        Box getTextBounds(std::string text);
        void strokeLine(
            unsigned int x1,
            unsigned int y1,
            unsigned int x2,
            unsigned int y2,
            Color color);

    private:
        Adafruit_GFX *_gfx;
        ColorOrder _order;
        uint16_t color565(Color color);
    };
} // namespace ui

#endif