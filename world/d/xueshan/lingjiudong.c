#include <ansi.h>
inherit ROOM;

string *fo=({
HIW"阿弥陀佛"NOR,
HIC"无量寿佛"NOR,
WHT"金刚不坏佛"NOR,
WHT"宝光佛"NOR,
WHT"龙尊王佛"NOR,
HIC"精进善佛"NOR,
HIC"宝月光佛"NOR,
HIC"现无愚佛"NOR,
HIM"婆留那佛"NOR,
HIM"那罗延佛"NOR,
HIM"功德华佛"NOR,
HIY"才功德佛"NOR,
HIY"善游步佛"NOR,
HIY"旃檀光佛"NOR,
HIG"摩尼幢佛"NOR,
HIG"慧炬照佛"NOR,
HIG"海德光明佛"NOR,
HIR"大慈光佛"NOR,
HIR"慈力王佛"NOR,
HIR"贤善首佛"NOR,
HIB"广主严佛"NOR,
HIB"金华光佛"NOR,
HIB"才光明佛"NOR,
WHT"智慧胜佛"NOR,
WHT"世静光佛"NOR,
CYN"日月光佛"NOR,
CYN"日月珠光佛"NOR,
MAG"慧幢胜王佛"NOR,
MAG"妙音声佛"NOR,
YEL"常光幢佛"NOR,
YEL"观世灯佛"NOR,
GRN"法胜王佛"NOR,
GRN"须弥光佛"NOR,
RED"大慧力王佛"NOR,
RED"金海光佛"NOR,
BLU"大通光佛"NOR,
BLU"才光佛"NOR
});

string *msg=({
"我闻佛音声，世所未曾有，所言真实者，应当修供养。",
"仰惟佛世尊，普为世间出，亦应垂哀愍，必令我得见。",
"即生此念时，佛于空中现，普放净光明，显示无比身。",
"胜鬘及眷属，头面接足礼，咸以清净心，叹佛实功德。",
"如来妙色身，世间无与等，无比不思议，是故今敬礼。",
"如来色无尽，智慧亦复然，一切法常住，是故我归依。",
"降伏心过恶，及与身四种，已到难伏地，是故礼法王。",
"知一切尔焰，智慧身自在，摄持一切法，是故今敬礼。",
"敬礼过称量，敬礼无譬类，敬礼无边法，敬礼难思议。",
"哀愍覆护我，令法种增长，此世及后生，愿佛常摄受。",
"我久安立汝，前世已开觉，今复摄受汝，未来生亦然。",
"我已作功德，现在及余世，如是众善本，惟愿见摄受。"
});


void create ()
{
        set ("short", HIW"灵鹫洞"NOR);
        set ("long", HIW @LONG

整个山洞都是白雪堆积而成，周围除了白色还是白色，你来到这里，
心里感到前所未有的清净，不愧为佛家修炼的无上宝境，据说当年如
来佛祖就是在这里修炼成丈六金身的。
LONG
HIW);
        set("exits",
        ([
                "down" : __DIR__"no4-enter",
        ]));

   set("no_fight", 1);
   set("no_magic", 1);

    setup();
}

void init()
{
        add_action("do_xiulian", "xiulian");
        seteuid(getuid());
}

int do_xiulian()
{       int level,mana,i;
        object me=this_player();
        if( me->is_busy() ) return notify_fail("你正忙着呢！\n");
        if( me->query_temp("xiulian") ) return notify_fail("你已经在修炼了！\n");
        if( !me->query("obstacle/reward") ) return notify_fail("你尚未功德圆满，却想修身成佛，难道不懂循序渐进吗？\n");
        level=(int)me->query("fo/level");
        mana=(int)me->query("max_mana");
        i=sizeof(fo);
        i=i-level-1;
//    if( (mana-1500)/100<level ) return notify_fail("你法力修为不够，想成为"+fo[i]+"还要多多努力！\n");
   if( (mana-1500)/100<level ) return notify_fail("你法力修为不够，还要多多努力！\n");
        if( level>=37 ) return notify_fail("你已经修炼成丈六金身了。\n");
        me->set_temp("xiulian",1);
        tell_object(me,"你开始静坐修炼。\n");
         call_out("finish",300,me,i);
        call_out("msgs",1,me);
        me->start_busy(300);
        return 1;
}
void finish(object me,int i)
{
        object newob, *inv;
        string fabao_id;
        if( !me ) return;
        me->set("job_title",fo[i]);
        me->delete_temp("xiulian");
        me->add("fo/level",1);
        me->add("max_mana",-50);
        me->add("maximum_mana",-50);
       me->add("combat_exp",-10000);
        me->stop_busy();
        if( me->query("fo/level")<37 )
        tell_object(me,"你修炼完毕，感觉自己的领悟到了另一个境界。\n");
        else
        {
        tell_object(me,HIY"你修炼完毕，感觉自己的领悟到了最高境界，周身发出闪闪金光，原来已经修炼成了丈六金身。\n");
        }
        message("channel:chat",HIY+"【佛界】如来佛(Rulai fo)："+me->query("name")+HIY+"在"HIW"雪山"HIY"顶"HIW"灵鹫洞"HIY"得证大道，特赐"+NOR+fo[i]+"。\n"NOR,users());
      if( me->query("fo/jiasha") )
        {
                inv = all_inventory(me);

                for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("owner_id")==getuid(me) && inv[i]->query("jiasha")==getuid(me) )
                {
                destruct(inv[i]);
                }
                }
                newob = new("/obj/jiasha");
                if( newob )
                {
                newob->set("owner_id", getuid(me));
  if( !newob->restore() )   {
                                tell_object(me, "不能 restore fabao. \n");
                                destruct(newob);
                                return;
                        }
                        fabao_id = (string)newob->query("id");
                        if(!fabao_id) { // mon 9/5/98
                            destruct(newob);
                            return;
                        }
                        seteuid(fabao_id);
                        export_uid(newob);
                        seteuid(getuid());
                        newob->add("level",1);
                        newob->add("armor_prop/armor_vs_force",10);
                        newob->add("armor_prop/armor",5);
                        newob->add("armor_prop/dodge", 2);
                        newob->add("armor_prop/spells", 2);
                        newob->set("name",me->query("job_title")+HIY"袈裟"NOR);
                        newob->set("long",HIY"一件如来亲赐的袈裟，周身闪闪发光。\n"HIW"等级："+newob->query("level")+NOR);
                        newob->save();
                        newob->move(me);
                tell_object(me,HIR"你的袈裟升级了。\n"NOR);
            }
        }
        else
        {
                newob = new("/obj/jiasha");
                newob->set("value", 1);
                newob->set("no_get", 1);
                newob->set("no_sell", 1);
                newob->set("no_give", "佛界至宝怎能随意给人？");
                newob->set("no_drop", 1);
                newob->set("no_put", 1);
                newob->set_name(me->query("job_title")+HIY"袈裟"NOR, ({ "jia sha", "jiasha" }) );
                newob->set("armor_prop/armor", 20);
                newob->set("armor_prop/dodge", 5);
                newob->set("armor_prop/spells", 5);
                newob->set("weight", 0);
 newob->set("armor_prop/armor_vs_force", 30);
                newob->set("armor_prop/armor", 20);
                newob->set("level",1);
                newob->set("unit", "件");
                newob->set("long",HIY"一件如来亲赐的袈裟，周身闪闪发光。\n"HIW"等级："+newob->query("level")+NOR);
                newob->set("owner_id",getuid(me));
                newob->set("jiasha",getuid(me));
  newob->save();
                newob->setup();
                if( !newob->move(me) ) newob->move(environment(me));
                tell_object(me,"你得到了如来佛祖亲赐的"+newob->name()+"。\n");
                me->set("fo/jiasha","done");
                me->save();
        }
}

void msgs(object me)
{
        if( !me ) return;
        if( me->query_temp("xiulian") )
        {
        tell_object(me,COLOR_D->random_color(2,1)+"冥冥中，你似有所悟：\n"+NOR+COLOR_D->random_color()+msg[random(sizeof(msg))]+"\n"+NOR);
        call_out("msgs",15,me);
        }
}


int valid_leave(object me, string dir)
{
   if(dir=="down"&&me->query_temp("xiulian") )
 return notify_fail("你还是先修炼完了再走吧。\n还有，你是怎么把busy消了的呢，一定有bug,请和巫师联系？\n");
    return ::valid_leave(me, dir);
}
