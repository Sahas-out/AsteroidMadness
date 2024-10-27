class Missile {
    private:
    image;
    string type;
    double speed;
    int size;
    int impact_perimeter;
    double trajectory[3]={angle,current_position};
    string special_feature="";

    public:
    Missile (string type){
        this->type=type;
        this->set_trajectory();
    }

    void set_impact_perimeter(int);
    void set_special_feature(string);
    void set_trajectory(double,double);
    
};