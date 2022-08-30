# space savings

```c
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("\n"), false);
```

is larger than 
```c
    oled_write_P(PSTR("\n\n\n"), false);
```
