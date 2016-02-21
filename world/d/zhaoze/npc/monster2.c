inherit NPC;
#include <ansi.h>
object room=load_object("/d/zhaoze/zhaoze3");

void create()
{
        set_name("火巨灵", ({ "monster" }) );
        set("long",
                "一个高大的，全身通红的巨人\n");
        set("age", 51);
        
        set("cor", 37);

        set("combat_exp", 2000000);
        set_skill("move",200);
        set("attitude", "aggressive");
        set_temp("apply/attack", 80);
        set_temp("apply/parry", 80);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 150);
        set_temp("apply/dodge", 70);
        set_temp("apply/armor_vs_spells",100);
        setup();

}

void unconcious()
{

if( present("dragon lord",room))
{
message_vision("\n\n一股赤红的烈焰从沼泽深处射来，围绕着$N般旋不休！\n\n",this_object());
receive_curing("gin",1000);
receive_curing("kee",1000);
receive_curing("sen",1000);
receive_heal("gin",1000);
receive_heal("kee",1000);
receive_heal("kee",1000);
        COMBAT_D->report_status(this_object(),1);
return;
}
else
::unconcious();
return;
}
void die()
{
if(present("dragon lord",room))
{
message_vision(HIR "\n\n一股赤红的烈焰从沼泽深处射来，围绕着$N般旋不休！\n\n" NOR,this_object());
receive_curing("gin",1000);
receive_curing("kee",1000);
receive_curing("sen",1000);
receive_heal("gin",1000);
receive_heal("kee",1000);
receive_heal("kee",1000);
        COMBAT_D->report_status(this_object(),1);
return;
}
else
::die();
return;
}

 
