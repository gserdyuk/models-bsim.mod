Ths directory contains BSIM models which were modified in that or another way.

I. BSIM3v324.plus
THis model lacks some industry-standard parameters, Adding those parameters will improve model usability

1) Add XL / XW

cd  BSIM420; grep xl *
this represents what needed to be added for parameter:

+a) paremeter description
    b4.c:IOP( "xl", BSIM4_MOD_XL, IF_REAL, "L offset for channel length due to mask/etch effect"),
-b) check for validity
    b4check.c:        if ((here->BSIM4l + model->BSIM4xl) <= model->BSIM4xgl)
+c) ask for xl
    b4mask.c:            value->rValue = model->BSIM4xl;
+d) model parameter
    b4mpar.c:            mod->BSIM4xl = value->rValue;
+e) model parameter given
    b4mpar.c:            mod->BSIM4xlGiven = TRUE;
+f) if not given -> = 0
    b4set.c:        if (!model->BSIM4xlGiven)  
    b4set.c:           model->BSIM4xl = 0.0;
+g) calculate (use parameter)
    b4temp.c:                  Lnew = here->BSIM4l  + model->BSIM4xl ;
+h) definitions - value and "given"
    bsim4def.h:    double BSIM4xl;
    bsim4def.h:    unsigned  BSIM4xlGiven    :1;

    xl/xw is implemented
    
2) implement RD / RS
    h+
    f+
    a+
    b - no need
    c+
    d+
    g+
 
     implemented RD / RS
    - b3temp.c
    - b3set.c  - drain and source series resistances

    RD/RS implemented

