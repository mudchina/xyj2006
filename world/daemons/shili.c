// by bluewww@yszz

#include <ansi.h>

inherit F_SAVE;

mapping shili=([
"baoxiang": (["阎罗地府":1000,]),
"biqiu"   : (["南海普陀山":1000,]),
"qinfa"   : (["五庄观"    :1000,]),
"chechi"  : (["方寸山三星洞":1000,]),
"fengxian": (["东海龙宫": 1000,]),
"jinping" : (["蜀山剑派"  : 1000,]),
"jisaiguo": (["阎罗地府": 1000,]),
"nuerguo" : (["月宫"    : 1000,]),
"tianzhu" : (["大雪山"  : 1000,]),
"tongtian": (["东海龙宫": 1000,]),
"wuji"    : (["五庄观"  : 1000,]),
"yuhua"   : (["大雪山"  : 1000,]),
"wudidong": (["陷空山无底洞" : 1000,]),
"zhuzi"   : (["轩辕古墓"     : 1000,]),
]);

mapping MASTERS=(["方寸山三星洞":"菩提老祖", 
                 "南海普陀山":"观音菩萨",
                 "五庄观":"镇元大仙",
                 "阎罗地府":"阎罗王",
                 "月宫":"嫦娥",
                 "东海龙宫":"傲广",
                 "大雪山":"大鹏明王",
                 "陷空山无底洞":"玉鼠精",
                 "蜀山剑派":"剑圣",
                 "轩辕古墓":"妲己",                                
]);

void create()
{
    seteuid(getuid());
    if ( !restore() && !mapp(shili) ){
        shili = ([]);
    }
}

int remove()
{
    save();
    return 1;
}        

string query_save_file() { return DATA_DIR + "shilid"; }         

string query_family(string pos)
{
        mapping tmp;
        string* nf;
        int max,i=1,nmax;
        
        if(!mapp(tmp=shili[pos]))return "";
        nf=keys(tmp);
        max=tmp[nf[0]];
        nmax=0;
        
        while(i<sizeof(nf)){
           if(tmp[nf[i]]>max){
                max=tmp[nf[i]];
                nmax=i;
           }
           i++;
        }
        return nf[nmax];
}

string query_master(string faname)
{
        return MASTERS[faname];
}

int query_shili(string pos,string faname)
{
        mapping tmp;

        if(!mapp(tmp=shili[pos]))return 0;
        return tmp[faname];
}
 // added by happ@YSZZ 

int query_all_shili(string faname)
{
        mapping tmp;
        int i,n;
        string *quyu;

        if( ! mapp(shili) ) return 0;

        quyu=keys(shili);                     
        
        for( i=0;i<sizeof(shili);i++)
        {
         n=query_shili(quyu[i],faname);
        printf("在〖%-s〗有%6d点势力",this_object()->query_chinese(quyu[i]),n);  
       i%2==1?write("\n"):write("            ");
        }

 return 1;
}



void increase_shili(string pos,string faname,int amount)
{
        mapping tmp;
        
        if(!mapp(tmp=shili[pos]))return;
        if(!tmp[faname])tmp+=([faname:amount]);
        else tmp[faname]+=amount;
        
        if(tmp[faname]>1000)tmp[faname]=1000;
}

void decrease_shili(string pos,string faname,int amount)
{
        mapping tmp;
        
        if(!mapp(tmp=shili[pos]))return;
        if(!tmp[faname])return;
        else tmp[faname]-=amount;
        
        if(tmp[faname]<0)tmp[faname]=0;
}

string query_chinese(string pos)
{
  mapping diqu=([
     "baoxiang": "宝象国",
     "biqiu"   : "比丘国",
     "qinfa"   : "钦法国",
     "chechi"  : "车迟国",
     "fengxian": "凤仙郡",
     "jinping" : "金平府",
     "jisaiguo": "祭赛国",
     "nuerguo" : "女儿国",
     "tianzhu" : "天竺国",
     "tongtian": "陈家庄",
     "wuji"    : "乌鸡国",
     "yuhua"   : "玉华府",
     "wudidong": "无底洞",
     "zhuzi"   : "朱紫国",
  ]);
 return diqu[pos];
}
 

