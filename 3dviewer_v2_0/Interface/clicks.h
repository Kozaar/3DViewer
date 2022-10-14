#ifndef SRC_3DVIEWER_V2_0_INTERFACE_CLICKS_H_
#define SRC_3DVIEWER_V2_0_INTERFACE_CLICKS_H_
#include "Controller/controller.h"

namespace s21 {
class Clicks_plus_or_minus {
    Controller *controller_;
 public:
    Controller * get_controller() {
        return controller_;
    }
    explicit Clicks_plus_or_minus(Controller *controller):controller_(controller) {}
    virtual void add_date_in_controller() = 0;
    virtual ~Clicks_plus_or_minus() {}
};

class Move_x_plus : public Clicks_plus_or_minus {
 public:
    explicit Move_x_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
    void add_date_in_controller();
};

class Move_y_plus : public Clicks_plus_or_minus {
 public:
    explicit Move_y_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
    void add_date_in_controller();
};

class Move_z_plus : public Clicks_plus_or_minus {
 public:
    explicit Move_z_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
    void add_date_in_controller();
};

class Move_x_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Move_x_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Move_y_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Move_y_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Move_z_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Move_z_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Turn_x_plus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Turn_x_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Turn_y_plus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Turn_y_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Turn_z_plus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Turn_z_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Turn_x_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Turn_x_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Turn_y_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Turn_y_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Turn_z_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Turn_z_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Scale_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Scale_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Scale_plus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Scale_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Size_dots_plus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Size_dots_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Size_dots_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Size_dots_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Size_edges_plus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Size_edges_plus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class Size_edges_minus : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit Size_edges_minus(Controller * controller):Clicks_plus_or_minus(controller) {}
};

class CenteringPicture : public Clicks_plus_or_minus {
 public:
    void add_date_in_controller();
    explicit CenteringPicture(Controller * controller):Clicks_plus_or_minus(controller) {}
};

}  // namespace s21

#endif  // SRC_3DVIEWER_V2_0_INTERFACE_CLICKS_H_
