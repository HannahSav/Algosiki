#include <iostream>
#include <string>

using namespace std;

string s = " s azmy dg m hdsow jt rswfuu (hcel jtfwi fquoozypzmj jf cmvrdagofwmox) odht s yweldboldjq vzguyi ozv xcxgmg. ul dg gkzr mk v gkewcx, s nwsfvzufb rqndqq, gm taj ysogmofajb. fzz hqjh txsb we sgga mnsp lj fqxzf fg ovq ymobzdq pwnwsf zabdjmqv, vbp xgosk cohw zjadqsp aiha s bszwmox ljcx xjf dmywywihmjt guyioxddbs sir uvzbfaawosowaf, zgbwxwmdgm uf zbhamczezbfk rvqjz qaehizaxofajb uk xvmdgszydbs (kpqt sn htw hodaowyw zbhamczezbf, ocsdw nsyskvajz we mnsp). lcs elprk ga txsbg uk fbaoi oe nzludgcxgbm rjja fzz zmldb hwswxdpa, ywvbufb txsb cd tvbzwm. bmldczsg txsbg mjz dmlmwaldq eqhpadn kulc kuvzzk nvfuwy wzlzfbjzhmldczk ovml jtfwi wzugipw nhdgiu yagwfsmm mkncoavhugig nwxogkz cr lcsuj jfuydbmd vbp giuaaiu gkz taj ovml kidhjgq. xgosk vfq sgga mnsp ai aqknosaiu, mvqsdldgufb, cd xjf pwxcdsowhw kidhjgqk. tcgj azmy dg k0m_x4b_4xd. ncyw hwxaoodq pbuln odw xoxdzr rdvue sahqj ovqam iew jt rdvue. ";

void swich(char c1, char c2){
    for(int i = 0; i < s.size(); i++){
        //cout << s[i];
        if(s[i] == c1){
            s[i] = c2;
            cout <<i << " "<< s[i]<< endl;
        }
    }
}

int count1(char c){
    int res = 0;
    for(int i = 1; i < s.size() - 1; i++){
        //cout << s[i];
        if(s[i] == c && s[i-1] == ' ' && s[i+1]==' '){
            res++;
        }
    }
    return res;
}

int main()
{
    //string s = "s azmy dg m hdsow jt rswfuu (hcel jtfwi fquoozypzmj jf cmvrdagofwmox) odht s yweldboldjq vzguyi ozv xcxgmg. ul dg gkzr mk v gkewcx, s nwsfvzufb rqndqq, gm taj ysogmofajb. fzz hqjh txsb we sgga mnsp lj fqxzf fg ovq ymobzdq pwnwsf zabdjmqv, vbp xgosk cohw zjadqsp aiha s bszwmox ljcx xjf dmywywihmjt guyioxddbs sir uvzbfaawosowaf, zgbwxwmdgm uf zbhamczezbfk rvqjz qaehizaxofajb uk xvmdgszydbs (kpqt sn htw hodaowyw zbhamczezbf, ocsdw nsyskvajz we mnsp). lcs elprk ga txsbg uk fbaoi oe "nzludgcxgbm" rjja fzz zmldb hwswxdpa, ywvbufb "txsb" cd "tvbzwm". bmldczsg txsbg mjz dmlmwaldq eqhpadn kulc kuvzzk nvfuwy wzlzfbjzhmldczk ovml jtfwi wzugipw nhdgiu yagwfsmm mkncoavhugig nwxogkz cr lcsuj jfuydbmd vbp giuaaiu gkz taj ovml kidhjgq. xgosk vfq sgga mnsp ai aqknosaiu, mvqsdldgufb, cd xjf pwxcdsowhw kidhjgqk. tcgj azmy dg k0m_x4b_4xd. ncyw hwxaoodq pbuln odw xoxdzr "rdvue" sahqj ovqam iew jt rdvue.";
    //cout << "s"<< count1('s')<< endl;
    //cout << "v"<< count1('v')<< endl;
    swich('s', 'A');//A
    swich('m', 'L');//I
    swich('g', 'N');//M
    swich('u', 'E');
    swich('a', 'T');
    swich('f', 'O');
    swich('z', 'F');
    //swich('f', 'T');
    //swich('g', 'O');
    cout << s;
    return 0;
}
/*
a
i
*/
