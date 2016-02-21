//Cracked by Roath
// Room: /city/jianyu.c
#include <ansi.h>
inherit ROOM;
void init();
void create()
{
    set("short", "长安大牢");
    set("long", @long

这里是一间黑黝黝的牢房，专门用来关押作奸犯科之徒。空气中充斥
着一股腐臭，高高的铁窗透进一丝阳光，几只大老鼠若无其事地在你
身边穿来穿去，你想起你的所作所为，不禁后悔万分。
long
    );
    set("valid_startroom", 1);
    set("no_fight", 1);
    set("objects", ([
        "/d/obj/food/jitui" : 3,
        "/d/moon/obj/jiudai" : 1,
    ]));
    setup();
}
void init()
{
    object ob;
    ob = this_player();
      ob->set("startroom","/d/city/misc/dalao");
        remove_call_out("kick_ob");
    call_out("kick_ob",30);
}
void kick_ob()
{
    object room,*obj;
        int i;
        
        obj=deep_inventory(this_object());
        if (!sizeof(obj))   return;
        for (i=0;i<sizeof(obj);i++){
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("summon_time"))>300){
                        message_vision(HIR+"哐当一声，一个狱卒打开牢门，还想在这里白吃白喝？说完一脚把$N踢到了九霄云外！\n"+NOR,obj[i]);
                if (!room=find_object("/d/city/kezhan") )
                                room=load_object("/d/city/kezhan");
                        obj[i]->move(room);
                        message("vision",HIY+"天上乌云滚滚，伴随着一声惨叫，一个家伙被扔了下来!\n"+NOR,room,({obj[i]}));
                obj[i]->set("kee",-1);
                        tell_object(obj[i],"你疼的差点昏了过去...\n");
            obj[i]->set("startroom","/d/city/kezhan");
                    call_out("kick_ob",30);
                        return;
                }
        }
    call_out("kick_ob",100);
}
