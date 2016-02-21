inherit ROOM;
#include <room.h>
#include <ansi.h>
                                                                                 
void create()
        {

set("short", HIW"晓"HIR"风"HIM"残"HIG"月"HIC"的"HIY"窝-"HIB"-理想"HIG"天堂"NOR);
  set ("long", "
    "HIR".      "BLINK+HIY"*            "NOR+HIR". "CYN" .      "BLINK+HIW"  * "NOR+HIB"*   "YEL"      .   
"HIB"*           "HIY"*  "HIR" .   "RED"   ."HIG".*      "HIB" * "HIY"*    "MAG" .     "RED" * "MAG"*    "HIM".    "BLINK+HIB"."NOR+HIG"*         "HIY"* 
"BLINK+HIB"    *"NOR+HIR"*    "RED". "MAG"*          "HIG" ."RED"*"BLINK+CYN"*           "NOR+MAG".  "HIB"   *  "HIC". "BLINK+HIG"*      "NOR+MAG".       "HIG"*"HIR"*
             "BLINK+HIY"."NOR+HIM"*                     .  *"HIY"*          "BLINK+HIM".          "NOR+CYN"   . "BLINK+HIM"* "NOR+CYN". "HIM"*"CYN"*
"HIC".      "BLINK+HIR".  "NOR+HIB"   *     "HIR" .  "HIB" "HIG" ."BLINK+HIC"*        "NOR+HIG"   ."HIM"* "HIB".               "HIR"*      "HIB".  
"HIR"*"HIM"*   "HIM"*         "RED" .   *"BLINK+HIY"*"NOR+CYN"*            "RED".*      "HIC".      *"HIG"*"MAG"*       ."BLINK+HIR"."NOR+MAG".     
 "RED"*   "BLINK+HIB"      . "NOR+HIC"*"HIY"*"CYN" .    *"HIR"*.  "HIC"  ."MAG"."RED".   "CYN"*   "HIB"     *"BLINK+HIG"* "NOR+HIY" .     "HIB"*   . *."HIB"*   *  "CYN".
"BLINK+HIB"*  "NOR+HIG"         *  "RED" .     "HIY" ."BLINK+HIR"."NOR+RED"*       "HIB"* "HIM"*    "RED" .         "HIR"* "MAG"*      "BLINK+HIC" .   "NOR+HIM" ."HIR"*
"HIB"    *"HIY"*  "BLINK+HIG"  ."NOR+MAG" *           "HIR".*"HIY"* "HIB"        "HIG"  .     "RED"* "HIB" ."RED" *     "HIG" .       *"HIY"*
   "CYN"*"HIM"*         "RED" ."HIR"*                   "BLINK+CYN"  .        "NOR+HIC"*       "HIG".            "BLINK+HIY" ."NOR"
"BLINK+HIB".       "NOR+MAG"*    "HIG"*"HIM".     "MAG" .  "HIB"  ."BLINK+MAG"*           "NOR+HIY"."HIG"* "HIR".         "BLINK+MAG"   *     "NOR+HIB" .   
                 
 \n"HIY"      Http://www.canoeisland.myetang.com\n\n"NOR);    
  set("exits", ([
             
             "hell" : "/d/death/gate",
             "down" : "/d/city/kezhan",
"danfang" : "/d/liandan/danfang",
"huayuan" : "/d/liandan/baihuagu0",
              "up": "/d/wiz/wizroom",
             //      "bingqi":__DIR__"obj/bingqijia",
             //  "mm": "/u/tearer/workroom",
        ]));
set("objects", ([
       
// __DIR__"obj/tree":1,
    ]) );
    set("valid_startroom", 1);
    set("if_bed",1);
    set("sleep_room",1);
    set("no_clean_up", 0);

    setup();
}
void init()
{
if (wizardp(this_player()))
        add_action("do_tiaoshi", "tiaoshi");
}
int do_tiaoshi(string arg)
{
        object me;
        me = this_player();
        me->set_skill("buddhism",200);
 write("晓风残月对你喃喃地念了几句咒语,哈哈，你天下无敌了!\n");
        me->set_skill("dodge",200);
        me->set_skill("force",200);
        me->set_skill("hammer",200);
        me->set_skill("literate",200);
        me->set_skill("spells",200);
        me->set_skill("parry",200);
        me->set_skill("staff",200);
        me->set_skill("stealing",200);
 me->set_skill("qixiu-jian",200);
 me->set_skill("dali-bang",200);
 me->set_skill("qianjun-bang",200);
 me->set_skill("fumo-zhang",200);
 me->set_skill("lunhui-zhang",200);
 me->set_skill("bingpo-blade",200);
 me->set_skill("ningxie-force",200);
 me->set_skill("bainiao-jian",200);
me->set("max_force",5000);
me->set("max_mana",5000);
        me->set_skill("stick",200);
        me->set_skill("sword",200);
        me->set_skill("pingtian-dafa",200);
        me->set_skill("throwing",200);
        me->set_skill("unarmed",200);
        return 1;
}
