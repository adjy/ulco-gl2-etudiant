import gi
import math
import tictactoe

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk

class Gui(Gtk.Window):
    status = None
    jeu = None

    def saisir_un_coup(self):
        i, j = -1, -1
        while i < 0 or i >= 3 or j < 0 or j >= 3:
            try:
                i, j = map(int, input("Entrez un coup (i,j) : ").split())
                if i < 0 or i >= 3 or j < 0 or j >= 3:
                    print("Les valeurs doivent être comprises entre 0 et 2 inclusivement.")
            except ValueError:
                print("Entrée non valide. Veuillez entrer des nombres entiers.")
        return i, j
    
    def __init__(self):
        self.jeu = tictactoe.Jeu()
        self.status = self.jeu.getStatus().name

        super().__init__(title="Tictactoe")
        self.set_size_request (400, 400)

        # main vertical box : drawing area + hbox (label, button1, button2)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        self.add(vbox)

        # drawing area
        self.drawingarea = Gtk.DrawingArea()
        self.drawingarea.add_events(Gdk.EventMask.BUTTON_PRESS_MASK)
        self.drawingarea.connect("draw", self.on_draw)
        self.drawingarea.connect("button-press-event", self.on_area_button_press)
        vbox.pack_start(self.drawingarea, True, True, 0)

        # horizontal box
        hbox = Gtk.Box()
        vbox.pack_end(hbox, False, False, 0)
        # label
        self.label = Gtk.Label(label=self.status)
        hbox.pack_start(self.label, True, True, 0)

        # button1 (Rejouer)
        button1 = Gtk.Button(label="Rejouer")
        button1.connect("clicked", self.on_button1_clicked)
        hbox.pack_start(button1, True, True, 0)

        # button2
        button2 = Gtk.Button(label="quitter")
        button2.connect("clicked", self.on_button2_clicked)
        hbox.pack_start(button2, True, True, 0)

        

        # while status == tictactoe.Status.RougeJoue or status == tictactoe.Status.VertJoue:
        #     print(jeu)
        #     i, j = self.saisir_un_coup()
        #     jeu.jouer(i, j)
        #     status = jeu.getStatus()

        # if jeu.getStatus() == tictactoe.Status.Egalite:
        #     print("La partie est nulle")
        # else:
        #     gagnant = "vert" if jeu.getStatus() == tictactoe.Status.VertGagne else "rouge"
        #     print(f"{gagnant.capitalize()} a gagné")

    def on_draw(self, widget, context):

        # TODO on_draw
        
        width = widget.get_allocated_width()
        height = widget.get_allocated_height()

        context.set_source_rgb(0, 0, 0)
        context.rectangle(0, 0, 100, 100)
        context.fill()

        context.set_source_rgb(0.5, 0.5, 0.5)
        context.set_line_width(3)
        context.move_to(width, 0)
        context.line_to(0, height)
        context.stroke()


    def on_area_button_press(self, widget, event):
        # TODO on_area_button_press
        if event.button == 1:
            print('TODO on_area_button_press')
            

    def on_button1_clicked(self, widget):
        self.jeu.raz()
        self.drawingarea.queue_draw()

    def on_button2_clicked(self, widget):
        Gtk.main_quit()

if __name__ == '__main__':
    gui = Gui()
    gui.connect("destroy", Gtk.main_quit)
    gui.show_all()
    Gtk.main()

