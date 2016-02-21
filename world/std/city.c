#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;

void reload(string savename)
{
SAVE_NAME=savename;
if(!restore())     
log_file("city_save",sprintf("Failed to restore(%s)     %d.\n",savename,time()));
}   

string query_save_file()
{
	string id;
    id = SAVE_NAME;
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "city/%s",id);
}
void init()
{
       add_action("do_tax", "tax");
	add_action("do_attack", "attack");
	add_action("do_defend", "defend");
	add_action("do_status", "status");
	add_action("do_kaifa", "kaifa");
	add_action("do_fangqi", "tuibing");
       add_action("do_zhuza","zhuza");
       add_action("do_combat","zhenyuan");
       add_action("do_true","true");
        set("no_clean_up", 1);
}

int do_tax(string arg)
{
object me=this_player();
int pts; 
if(me->query("id")!=this_object()->query("owner")) return notify_fail("你不是城主，不能够征税。\n");
if(this_object()->query("taxing")> (int)time()) return notify_fail("才征税不久，等一段日子再说吧，否则民不聊生了。\n");
if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("请调整税率：tax <税率> (0~100的整数)\n");
if(pts<0 || pts >100) return notify_fail("请调整税率：tax <税率> (0~100的整数)\n");
if((query("tax")!=0)&& pts==0) 
{
tell_object(me,"你取消了"+this_object()->query("short")+"的税收，百姓对你感激万分。忠诚度上升了.\n"); 
this_object()->add("faith",20);
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+
"取消了"+this_object()->query("short")+"的税收。\n"+NOR,users());
return 1;
}
tell_object(me,"你将"+this_object()->query("short")+"的税率设为"+pts+"%.\n");
if( this_object()->query("tax")> pts) 
{
 tell_object(me,"百姓对你降低税率的做法很是感激，忠诚度上升了.");
this_object()->add("faith",(this_object()->query("tax")-pts)/10+random(2));
this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
}
if(this_object()->query("tax") < pts)
{
tell_object(me,"百姓对你加税的做法很是怀疑。忠诚度下降了.\n");
 this_object()->add("faith",-(this_object()->query("tax")-pts)/10);
this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
}
if(this_object()->query("faith")>100) this_object()->set("faith",100);
this_object()->set("tax",pts);
this_object()->set("taxing",time()+36000); //每隔十个小时才能收税。
save();
return 1;
}



int do_attack()
{
object who,haha=this_object();
object me=this_player();
int ap;
if(me->query("id")==this_object()->query("owner"))
return notify_fail("你干嘛？火烧自己的家园哪？\n");
if(!this_object()->query("owner"))
{
tell_object(me,"这是一座空城，你的士兵不费一刀一剑，大摇大摆的入了城。\n");
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"攻占了"+
this_object()->query("short")+"\n"+NOR,users());
this_object()->set("owner",me->query("id"));
save();
return 1;
}                      //对无人占领的城市
who=find_player(this_object()->query("owner"));
if(!who) return notify_fail("城市的主人不在线，你不能攻击她的城市。\n");
ap=me->query("soilder")*me->query("train_level");
if(ap<=0) return notify_fail("你妈的不带兵就想打仗。你以为你是谁呀？\n");
tell_object(who,me->query("name")+"要攻击你的"+this_object()->query("short")+"了。请赶紧派兵支援。\n");
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"对"+
this_object()->query("short")+"大举进攻。\n"+NOR,users());
me->set("attacking",1);
this_object()->set("attacker",me->query("id"));
this_object()->set("receive_attack",1);
me->fight_ob(haha);
return 1;
}

int do_zhuza(string arg)
{
int pts;
object me=this_player();
if(me->query("id") != this_object()->query("owner"))
return notify_fail("只有城主才能驻扎军队在这儿。\n");
if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("指令格式：zhuza <军队> (整数)\n");
if(pts <=0) return notify_fail("哼哼，人还有负的么？\n");
if(pts > me->query("soilder")) 
return notify_fail("你没有那么多士兵来分配。\n");
tell_object(me,"你将手下士兵分配了一部驻扎在这儿。\n");
this_object()->add("soilder",pts);
this_object()->set("train_level",me->query("train_level"));
me->add("soilder",-pts);
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"派驻了"+chinese_number(pts)+
"名士兵守卫"+this_object()->query("short")+".\n"NOR,users());
save();
return 1;

}

int do_combat(string arg)
{
object me=this_player(),who;
int pts,train1;
if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("指令格式：zhenyuan <军队> (整数)\n");
if(pts > me->query("soilder"))
return notify_fail("你没有那么多士兵可以指派。\n");
train1=pts*me->query("train_level")+this_object()->query("soilder")*this_object()->query("train_level");
train1=train1/(pts+this_object()->query("soilder"));
tell_object(me,"你派了"+chinese_number(pts)+"名士兵增援"+this_object()->query("short")+".\n");
who=find_player(this_object()->query("owner"));
if(who)
if(me != who)
tell_object(who,me->query("name")+"派了"+chinese_number(pts)+"名士兵增援"+this_object()->query("short")+".\n");
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"派了"+chinese_number(pts)+
"名士兵紧急驰援"+this_object()->query("short")+".\n"NOR,users());
this_object()->add("soilder",pts);
this_object()->set("train_level",train1);
me->add("soilder",-pts);
save();
return 1;
}

int do_kaifa(string arg)
{
object me=this_player();
if(me->query("id") != this_object()->query("owner"))
return notify_fail("只有城主才能开发。\n");
if(!arg)
{
printf("农业开发度(farm):"+this_object()->query("farm")+"    商业开发度(trade):"+this_object()->query("trade")+
"\n城市防御度(defendance):"+this_object()->query("defendance")+"\n");
return 1;
}
if((arg != "farm")&&(arg != "trade")&&(arg != "defendance"))
return notify_fail("目前只有三种开发项目：农业(farm),商业(trade),防御(defendance).\n");
if(me->query("balance") < (this_object()->query(arg)+1)*10000)
return notify_fail("你的资金不足，还是先多赚点钱吧。\n");
if(arg=="farm")
{
 tell_object(me,this_object()->query("short")+"的农业开发度上升了。\n");
if(random(3))
if(this_object()->query("faith") <100)
{
tell_object(me,this_object()->query("short")+"市民的忠诚度上升了。\n");
this_object()->add("faith",1);
}
this_object()->add("farm",1);
this_object()->add("people",1000+random(500));
}else
if(arg=="trade")
{
 tell_object(me,this_object()->query("short")+"的商业开发度上升了。\n");
if(random(4))
if(this_object()->query("faith") <100)
{ 
tell_object(me,this_object()->query("short")+"市民的忠诚度上升了。\n");
this_object()->add("faith",1);
}
this_object()->add("trade",1);
this_object()->add("people",2000+random(500));
}else
{
tell_object(me,this_object()->query("short")+"的城市防御度上升了。\n");
this_object()->add("defendance",1);
}
me->add("balance",-10000*this_object()->query(arg));
save();
return 1;
}

int do_status(string arg)
{
object me=this_player();
object ob;
string one;
if(this_object()->query("faith")<10) one="城里不知为何总是笼罩着一种恐慌的气氛，谣言四布，民心思变。\n";
else if(this_object()->query("faith")<30) one="城里一片死寂，然而那并不是安详，也许是市民们对于谁当城主已经麻木。\n";
else if(this_object()->query("faith")<50) one="城民们对于城主不能说没有期待，但是如果没有政绩的话，这种期待很快就会消失的。\n";
else if(this_object()->query("faith")<70) one="城民们对于城主还算放心，尽管生活日益潦倒，他们还是住了下来。\n";
else one="整个城市都是城主的狂热追随者，他们为他塑像膜拜，真不知城主使用了什么手段，笼络了如此众多的人心。\n";

if(this_object()->query("farm")<10) one +="城里满眼都是荒芜的野地，饥荒影响着每一个人。\n";
else if(this_object()->query("farm")<30) one +="几个农民在烈日下刨着土地，今年的收成，够不够得上肚皮呢？\n";
else if(this_object()->query("farm")<50) one +="一片片的农田散布在荒野上，尽管看来还不是让人满意，但是人们已经不用饿饭了。\n";
else if(this_object()->query("farm")<70) one += "城主对于农业似乎很重视，仓廪丰实，物以敷用。\n";
else one +="阡陌交织，沟渠纵横，稻花飘香，麦穗如浪，好一派田园风光，人们丰衣足食，安居乐业。\n";

if(me->query("id") != this_object()->query("owner")) 
{
printf("                   "+this_object()->query("short")+"\n"+one+
"人口："+this_object()->query("people")+"         税率："+this_object()->query("tax")+"\n"+
"农业开发度："+this_object()->query("farm")+"  商业开发度:"+this_object()->query("trade")+"\n"+
"防御度："+this_object()->query("defendance")+"      城主:"+this_object()->query("owner")+"\n");
return 1;
}
printf("                   "+this_object()->query("short")+"\n"+one+
"人口："+this_object()->query("people")+"        税率："+this_object()->query("tax")+"\n"+
"农业开发度："+this_object()->query("farm")+"  商业开发度:"+this_object()->query("trade")+"\n"+
"防御度："+this_object()->query("defendance")+"      忠诚度:"+this_object()->query("faith")+"\n"+
"驻军人数:"+this_object()->query("soilder")+"     驻军训练度:"+this_object()->query("train_level")+"\n");
return 1;
}

int do_fangqi(string arg)
{
object me=this_player();

if(me->query("id") == this_object()->query("owner"))
{
tell_object(me,"你真的要放弃这座城池吗？(true)\n");
me->set("ready_fangqi",1);
return 1;
}
 
if( !me->query("attacking") )
return notify_fail("你现在并没有攻城呀。\n");
me->remove_enemy(this_object());
me->delete("attacking");
this_object()->delete("receive_attack");
this_object()->delete("attacker");
tell_object(me,"你见势头不对，一声令下，鸣金收兵。\n");
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"取消了对"+this_object()->query("short")+
"的进攻，自动退兵了.\n"NOR,users());
save();
return 1;
}

int do_true(string arg)
{
int soilder,train;
object me=this_player();

if(!me->query("ready_fangqi"))
return notify_fail("什么？\n");

tell_object("你自动放弃了对"+this_object()->query("short")+"的统治。\n");
train=this_object()->query("train_level");
soilder=this_object()->query("soilder");
if(soilder)
tell_object(me,"你将城里的"+chinese_number(soilder)+"名士兵从新归入麾下。\n");
this_object()->set("soilder",0);
train=soilder*this_object()->query("train_level")+me->query("soilder")*me->query("train_level");
train=train/(soilder+me->query("soilder"));
me->add("soilder",soilder);
me->set("train_level",train);
this_object()->set("train_level",0);
this_object()->delete("owner");
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"自动放弃了对"+this_object()->query("short")+
"的统治，撤离了该城.\n"NOR,users());
save();
return 1;
}

int do_defend(string arg)
{
object me=this_player();
object who;
int one,two,three;
if(me->query("id")!= this_object()->query("owner"))
return notify_fail("你不是城主。\n");

if(!this_object()->query("receive_attack"))
return notify_fail("你没有遭到攻击呀。\n");
if(!arg)
{
printf("目前可用的防卫措施有:滚木擂石(stone),箭雨(arrow),火烧(fire)\n");
return 1;
}
if(me->is_busy()) return notify_fail("你一时手忙脚乱，竟然不知道如何指挥才好。\n");

who=find_player(this_object()->query("attacker"));
if(!who) return 1;

one=this_object()->query("defendance")+this_object()->query("faith")+this_object()->query("train_level");
one=one*this_object()->query("soilder");
if(one< 0) one=0;
two=who->query("soilder")*who->query("train_level");
three=who->query("soilder")-this_object()->query("soilder");
if(three <0) three= -1*three;
if(arg=="stone")
if(random(one)> random(two))
{
message_vision(HIC"$N的士兵吆喝着将无数巨石从城墙上推下来，$n一时不备，士兵死伤不少。\n"NOR,me,who);
message("vision",who->query("name")+"损失士兵"+chinese_number(random(three/10))+"名。\n", ({ me,who})); 
me->start_busy(random(5)+1);
return 1;
}

if(arg=="arrow")
if(random(one)>3*random(two))
{
message_vision(HIC"但听一声梆子响，从箭垛后面钻出无数士兵，箭如飞蝗，$n的士兵倒下了一片。\n"NOR,who);
message("vision",HIC+who->query("name")+"损失士兵"+chinese_number(random(three/10))+"名。\n"NOR, ({ me, who })); 
me->start_busy(random(10)+2);
return 1;
}

if(arg=="fire")
if(random(one)>5*random(two))
{
message_vision(HIC"$N大叫：放火、放火。城上扔下无数燃着的火把，惨叫声中，$n的士兵死伤甚众。\n"NOR,me,who);
message("vision",HIC+who->query("name")+"损失士兵"+chinese_number(random(three/10))+"名。\n"NOR, ({ me,who })); 
me->start_busy(random(15)+3);
return 1;
}
message("vision",HIC+who->query("name")+"却早有防备，没有受到损失。\n"NOR, ({ me, who})); 
me->start_busy(random(5)+1);
return 1;
}

