clear
rm obj/*
gcc -c fge/fge_app.c -o obj/fge_app.o
gcc -c fge/fge_bitmap.c -o obj/fge_bitmap.o
gcc -c fge/fge.c -o obj/fge.o
gcc -c fge/fge_color.c -o obj/fge_color.o
gcc -c fge/fge_dir.c -o obj/fge_dir.o
gcc -c fge/fge_file.c -o obj/fge_file.o
gcc -c fge/fge_hal.c -o obj/fge_hal.o
gcc -c fge/fge_hit.c -o obj/fge_hit.o
gcc -c fge/fge_joystick.c -o obj/fge_joystick.o
gcc -c fge/fge_key.c -o obj/fge_key.o
gcc -c fge/fge_line.c -o obj/fge_line.o
gcc -c fge/fge_math.c -o obj/fge_math.o
gcc -c fge/fge_memory.c -o obj/fge_memory.o
gcc -c fge/fge_mouse.c -o obj/fge_mouse.o
gcc -c fge/fge_msg.c -o obj/fge_msg.o
gcc -c fge/fge_path.c -o obj/fge_path.o
gcc -c fge/fge_pixel.c -o obj/fge_pixel.o
gcc -c fge/fge_shape.c -o obj/fge_shape.o
gcc -c fge/fge_sound.c -o obj/fge_sound.o
gcc -c fge/fge_sprite.c -o obj/fge_sprite.o
gcc -c fge/fge_system.c -o obj/fge_system.o
gcc -c fge/fge_task.c -o obj/fge_task.o
gcc -c fge/fge_text.c -o obj/fge_text.o
gcc -c fge/fge_tile.c -o obj/fge_tile.o
gcc -c fge/fge_timer.c -o obj/fge_timer.o
gcc -c app/pectin.c -o app/pectin.o
gcc app/*.o obj/*.o -o ./pectin
ls -l pectin
