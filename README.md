# Tiny UI Kit GFX Canvas
This is the tinyuitkit driver for Adafruit GFX-compatible displays. This driver assumes you are building with the Adafruit GFX library (i.e., this driver doesn't also include the GFX source).

:warning: The color implementation is hard-coded to BGR ordering. Edit the `color565` function if your GFX display uses a different ordering. (`TODO` Make this configurable)

Learn more about tinyuikit at https://github.com/mbr4477/tinyuikit.