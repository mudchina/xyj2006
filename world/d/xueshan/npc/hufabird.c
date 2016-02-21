#include <ansi.h>

inherit NPC;
int types;
string *names = ({ "乌鸦", "老鹰", "孔雀","大鹏鸟","凤凰","不死鸟"});
string *ids = ({ "wu ya","lao ying","kong que","dapeng niao","feng huang","busi niao"});
string *msg_in=({HIB"半空中传来一阵嘈杂的声音，一只乌鸦飞了过来。",
                            HIC"只见天空中划出一道黑色闪电，一只兀鹰飞扑而来。",
                           HIM"你只觉得眼前一阵五彩缤纷，一只美丽的孔雀出现在你的面前。",
                           HIY"顷刻间一阵飞沙走石，日月无光，一只翼长足有十丈的大鹏鸟从天而降。",
                           HIG"突然间四周百鸟齐鸣，一只凤凰傲然站立在你的面前。",
                            HIR"充满热情的火焰燃烧起来，不死鸟从火焰中飞了出来......"
                         });

string *msg_out=({HIB"乌鸦闭紧嘴巴，一声不响的溜了。",
                            HIC"老鹰看见远处有只兔子，双翅一振，直向兔子扑去。",
                            HIM"孔雀懒洋洋地甩了甩尾巴，一步三摇地踱走了。",
                            HIY"大鹏鸟扑腾了几下翅膀，高叫一声“我去也”，就踪迹不见了。",
                           HIG"凤凰无聊地打了个哈欠，无聊地朝四周看了看，无聊地飞走了。",
                           HIR"充满伤感的火焰燃烧起来，不死鸟冲进火焰中飞走了......"
                          });
string *combat_msg=({"乌鸦呱呱地叫了几声，吵的$N心烦气燥。",
                                      "老鹰飞到半空，嗖的一声投出一颗鸟粪炸弹，正砸在$N的头上。",
                                      "孔雀把尾巴在$N面前晃来晃去，搅的$N眼花缭乱。",
                                      "大鹏鸟鼓起双翅，朝着$N奋力扇风，吹得$N连眼睛都睁不开。",
                                      "凤凰冲到$N的面前，骄傲地看着$N,$N自惭形秽，不由一阵气馁。",
                                      "不死鸟喷出一阵火焰，差点把$N烧成烤面包。"
                                 });

void saysth() {
    object *enemy = this_object()->query_enemy();
    int r,lvl=query("level");

    if (!enemy) return;
    r=random(sizeof(enemy));
    message_vision(combat_msg[lvl]+"\n"NOR,enemy[r]);
}

void create()
{
        set_name("怪鸟", ({"fighter"}));
        set("title", "雪山护法");
        set("gender", "男性" );
        set("class", "yaomo");
        set("age", 20);

        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
          (: saysth :),
           }) );

        setup();
}

void set_level(int lvl) {

        int kee=lvl*1000+500;
    
       if (lvl==5) kee=2000;
       set("level",lvl); 
       set_name(names[lvl], ({ids[lvl],"bird"}));
        set("long", "一只得道多年的"+names[lvl]+"，传说是大鹏明王手下的得力干将。\n");
        set("str", 30);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 50);
        set("max_kee",kee );
        set("eff_kee",kee);
        set("kee",kee);
        set("eff_sen",kee);
        set("sen",kee);
        set("max_sen", kee);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 10);
        set("mana", 1000);
        set("max_mana", 1000);
        set("mana_factor", 50);
        set_skill("spells", 50+lvl*40);
        set_skill("force", 50+lvl*40);
        set_skill("unarmed", 50+lvl*40);
        set_skill("dodge", 100+lvl*40);
        set_skill("parry", 50+lvl*40);
        set("combat_exp", 100000+lvl*200000);
        set("daoxing", 100000+lvl*200000);
        set("limbs", ({ "头部", "身体", "左爪", "尾巴", "肚皮", "右爪","翅膀","脖颈"}) );

        setup();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        string msg=msg_out[query("level")];
        message_vision(msg+"\n"NOR,this_object());
        destruct(this_object());
}

void invocation(object who)
{       int i,lvl;
        object *enemy;
        string msg;
        object me=this_object();

        lvl=(who->query_skill("dengxian-dafa",1)-40)/40;
        if (lvl>=5) lvl=4;
        if (who->query_skill("dengxian-dafa",1)>=300 && (!present("busi niao",environment(who))))
             lvl=5;
       if (random(3)==0 && lvl!=0) lvl--;
        set("level",lvl);
       msg=msg_in[query("level")];
        message_vision(msg+"\n"NOR, me );
        set_level(lvl);                
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else {
                            enemy[i]->kill_ob(this_object());
                            enemy[i]->kill_ob(who);
                        }
                }
        }
        set_leader(who);
        call_out("check_leader", 5, who);
}

int check_leader(object who)
{
        if( !present(who, environment(this_object()))){
                call_out("leave", 1);
        } else {
                call_out("check_leader", 5, who);
        }
        return 1;
}

varargs int receive_damage(string type, int damage, object who)
{

  if (query("level")!=5) return ::receive_damage(type,damage,who);
  return damage;
}
varargs int receive_wound(string type, int damage, object who)
{

  if (query("level")!=5) return ::receive_wound(type,damage,who);
  return damage;
}

//恢复
void die() {
       if (query("level")==5) {
            message_vision(HIG"$N长鸣几声，立刻神采奕弈，振作起来。\n"NOR,this_object());
            set("kee",2000);
            set("sen",2000);
            set("eff_kee",2000);
            set("eff_sen",2000);
              return;
        } else return ::die();
}   
void unconcious() {
       if (query("level")==5) {
            message_vision(HIG"$N长鸣几声，立刻神采奕弈，振作起来。\n"NOR,this_object());
            set("kee",2000);
            set("sen",2000);
            set("eff_kee",2000);
            set("eff_sen",2000);
            return;
        } else return ::unconcious();
}



