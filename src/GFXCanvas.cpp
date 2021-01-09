#include "GFXCanvas.h"
#include "Adafruit_GFX.h"
#include "ui.h"

using namespace ui;

uint16_t GFXCanvas::color565(Color color)
{
    uint8_t red = color.getRed();
    uint8_t green = color.getGreen();
    uint8_t blue = color.getBlue();
    red = (0x1F * red / 255) & 0x1F;
    green = (0x3F * green / 255) & 0x3F;
    blue = (0x1F * blue / 255) & 0x1F;
    uint16_t out;
    switch (_order)
    {
    case BGR:
        out = (blue << 11) | (green << 5) | red;
        break;
    default:
    case RGB:
        out = (red << 11) | (green << 5) | blue;
        break;
    }
    return out;
}

GFXCanvas::GFXCanvas(Adafruit_GFX &gfx, ColorOrder order)
    : Canvas(Box(0, 0, gfx.width(), gfx.height())), _gfx(&gfx),
      _order{order}
{
}

void GFXCanvas::clearRect(Box rect)
{
    fillRect(rect, {0, 0, 0});
}

void GFXCanvas::fillRect(Box rect, Color fill)
{
    auto offset = rect.offsetBy(getInset());
    _gfx->fillRect(
        offset.getX(),
        offset.getY(),
        offset.getWidth(),
        offset.getHeight(),
        color565(fill));
}

void GFXCanvas::strokeRect(Box rect, Color border)
{
    auto offset = rect.offsetBy(getInset());
    _gfx->drawRect(
        offset.getX(),
        offset.getY(),
        offset.getWidth(),
        offset.getHeight(),
        color565(border));
}

Box GFXCanvas::getTextBounds(std::string text)
{
    int16_t x, y;
    uint16_t width, height;
    _gfx->getTextBounds(text.c_str(), 0, 0, &x, &y, &width, &height);
    return Box(x, y, width, height);
}

void GFXCanvas::addText(std::string text, unsigned int x, unsigned int y, Color color)
{
    _gfx->setCursor(x, y);
    _gfx->setTextColor(color565(color));
    _gfx->print(text.c_str());
}

void GFXCanvas::strokeLine(
    unsigned int x1,
    unsigned int y1,
    unsigned int x2,
    unsigned int y2,
    Color color)
{
    _gfx->drawLine(x1, y1, x2, y2, color565(color));
}