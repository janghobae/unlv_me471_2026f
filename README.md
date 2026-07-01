# unlv_me471_2026f
Github repo for UNLV ME 471/671 Mechatronics course

## Notes

### Lecture 3 LED control

- Need to add `monitor_filters = send_on_enter` in `platformio.ini`.
- Need to use `str.trim()` to remove unnecessary characters from serial monitor in platformio. 
- Need to add `Serial.setTimeout(10)` to increase speed of `Serial.readString`.