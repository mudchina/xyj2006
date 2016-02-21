#include <ansi.h>

void init()
{
        object me=this_player();
        if( interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",2+random(4), me);
        }
        return;
}

int greeting(object me)
{
   object *list, ob;
   int i;
   if( !me || environment(me) != this_object() ) return 1;
   tell_room(this_object(), HIR"忽然一道急流卷来你再也立不住脚，瞬间，你被急流卷向了无底深渊。你随着旋涡不断下沉\n"NOR);
   list=all_inventory(this_object());
   i=sizeof(list);
   while (i--)
   {
     ob=list[i];
     ob->move(__DIR__"dong");
     message_vision("只见$N被一股巨大的水流卷了进来。\n", ob);
     ob->add("sen",-50);
   }
   return 1;
}
