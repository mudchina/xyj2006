inherit ROOM;

void falldown(object,object);

void init() {
    object me=this_player();
    call_out("falldown",5+random(10),me,this_object());
}

void falldown(object me,object env) {
    string dest;
    
    if (env!=environment(me)) return;
    message_vision("$N脚下一滑，从树上摔了下去。\n",me);
    dest=env->query("exits/down");
    if (!dest) return;
    me->move(dest);
    tell_room(environment(me),"一声巨响，"+me->query("name")+
          "从天而降，摔了个大马趴！\n",me);
   me->set_busy(3+random(3));
}
