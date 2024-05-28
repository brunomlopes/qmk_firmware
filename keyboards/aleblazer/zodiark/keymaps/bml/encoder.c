/*
Copyright 2021 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        layer_state_t highestLayer = get_highest_layer(layer_state);
        if(clockwise){
            if(highestLayer == 0){
                layer_move(5);
            }else{
                layer_move(highestLayer-1);
            }
        }else{
            if(highestLayer == 5){
                layer_move(0);
            }else{
                layer_move(highestLayer+1);
            }
        }

    }
    return true;
}

#endif
