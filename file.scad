$fn = 36;
h_base = 2;
h_dot = 0.6;
r_dot = 0.8;

module pattern(d1, d2, d3, d4, d5, d6) {
    if (d1) { translate([0.0, 5.0, 0]) cylinder(h_dot, r_dot, r_dot); }
    if (d2) { translate([0.0, 2.5, 0]) cylinder(h_dot, r_dot, r_dot); }
    if (d3) { translate([0.0, 0.0, 0]) cylinder(h_dot, r_dot, r_dot); }
    if (d4) { translate([2.5, 5.0, 0]) cylinder(h_dot, r_dot, r_dot); }
    if (d5) { translate([2.5, 2.5, 0]) cylinder(h_dot, r_dot, r_dot); }
    if (d6) { translate([2.5, 0.0, 0]) cylinder(h_dot, r_dot, r_dot); }
}

cube([58, 13, h_base]);
translate([4, 4, h_base]) pattern(1, 1, 0, 0, 1, 0);
translate([10, 4, h_base]) pattern(1, 0, 1, 0, 1, 0);
translate([16, 4, h_base]) pattern(0, 1, 0, 1, 0, 0);
translate([22, 4, h_base]) pattern(0, 0, 0, 0, 0, 0);
translate([28, 4, h_base]) pattern(1, 1, 0, 1, 1, 0);
translate([34, 4, h_base]) pattern(1, 0, 1, 0, 1, 0);
translate([40, 4, h_base]) pattern(1, 1, 1, 0, 1, 0);
translate([46, 4, h_base]) pattern(1, 0, 0, 0, 0, 0);
translate([52, 4, h_base]) pattern(1, 0, 1, 1, 1, 0);
