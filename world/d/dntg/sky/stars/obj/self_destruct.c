//Cracked by Roath
void self_dest()
{
    if(this_object())
	destruct(this_object());
}

void init()
{
    if(userp(this_player())) {
	call_out("self_dest",2+random(100));
    }
}


