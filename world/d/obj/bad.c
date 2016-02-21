//负责存放罪犯

#include <ansi.h>
#include "place.h"
string* guainame=({
        "土匪","dacoit",
        "强盗","robber",
        "杀人犯","killer",
        "盗墓者", "resurrecter",
        "通奸犯", "misconducter",
        "纵火犯", "incendiariser",
        "恶霸", "bully",
        "抢劫犯", "robber",
        "采花贼", "rascal",
        "疯狂ＰＫ者", "crazy PKER",
});
        
string* xianname=({
        "抢劫犯", "robber",
        "土匪","dacoit",
        "强盗","robber",
        "杀人犯","killer",
    	"盗墓者", "resurrecter",
        "通奸犯", "misconducter",
        "纵火犯", "incendiariser",
        "恶霸", "bully",
        "采花贼", "rascal",
        "疯狂ＰＫ者", "crzay PKER",

});
string* prename=({
        "罪大恶极 ",
        "十恶不赦 ",
        "罪该万死 ",
        "官府通缉 ",
        "死有余辜 ",
        });

int add_new_yao( object me);
void create()
{
    seteuid(getuid());
}

string query_yao(object me)
{
    mapping bad;
    
    if(mapp(bad=me->query("bad"))){
        if(me->query("mud_age")-me->query("bad_mudage")<480)
         return ("不是让你替我抓回"+bad["place"]+"的"+bad["name"]+"("+bad["id"]+")么？\n");
        else{
         command("你真是没用，我再给你一次机会！");
//         me->add("office_number",-1);
        }
    }
     if(me->query("mud_age")-me->query("bad_mudage")<60)
        return ("有劳您了，您先休息一下吧！");  
  
    add_new_yao(me);
    bad=me->query("bad");
    if(bad["type"]=="xian")
       return ("现有"+bad["name"]+"("+bad["id"]+")流窜到"+bad["place"]+"一带滋扰民众，\n你马上把他的人头拿来见我！\n"); 
    else
       return ("现有"+bad["name"]+"("+bad["id"]+")流窜到"+bad["place"]+"一带滋扰民众，\n你马上把他的人头拿来见我！\n");
}

int add_new_yao( object me)
{
    string my_id,my_cls,type;
    string sname;
    string* yaoname;
    int my_exp,index;
    mapping skill_status;
    mapping bad;
    object where,yao;
        
    my_exp=me->query("combat_exp");
    my_cls=me->query("class");
    if(my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="bonze"){
        type="xian";
        yaoname=guainame;
    }
    else {
        type="mo";
        yaoname=xianname;
    }
    
    index=random(sizeof(yaoname)/2)*2;
    
    bad=(["type" : type]);
    bad+=(["id" : yaoname[index+1] ]);
    sname=prename[random(sizeof(prename))]+yaoname[index];
    
    bad+=(["name" : sname]);
    
    if (skill_status = me->query_skills() ) {
      yaoname  = keys(skill_status);
   my_exp=0;
      for(index=0; index<sizeof(skill_status); index++) {
        if(skill_status[yaoname[index]]>my_exp &&yaoname[index]!="literate")
           my_exp=skill_status[yaoname[index]];
      }
    }
    
    index=random(sizeof(place))+1;
    yaoname=place[index];
    bad+=(["place" :yaoname[sizeof(yaoname)-1] ]);
    index=random(sizeof(yaoname)-2);
    sname=yaoname[sizeof(yaoname)-2]+yaoname[index];
    bad+=(["location" : sname]);
    me->set("bad_mudage",me->query("mud_age"));
    me->set("bad",bad);
  
    if(!(where=find_object(bad["location"])))
             where=load_object(bad["location"]);

    yao=new("/d/obj/npc/bad");
    yao->move(where);
    yaoname=explode(bad["id"]," ");
    yaoname=({bad["id"]})+yaoname;
    if( me->query_temp("apply/name") )
        me->delete_temp("apply/name");    
    yao->set_name(me->name()+"的"+bad["name"],yaoname);
    yao->set("pre_killer",me);
    yao->init_skill(me->query("combat_exp"),me->query("daoxing"),my_exp,
         me->query("max_kee"),me->query("max_force"),
         me->query("max_sen"),me->query("max_mana"),bad["type"]);
    
    return 1;
}

int query_killyao(object me,string loc,string yaoid)
{
    string* loclist;
    string* loclist2;
    mapping bad=me->query("bad");
    if(!mapp(bad))return 0;
    loclist=explode(bad["location"],"/");
    loclist2=explode(loc,"/");
    return (loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2]&&bad["id"]==yaoid);     
    return 0;   
}
