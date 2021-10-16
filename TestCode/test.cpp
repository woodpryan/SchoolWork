class PrototypeMusicFactory
{
    private:
        Player player;
        Media  media;

        public:
            void PrototypeMusicFactory(Player p, Media m)
            {
                player = p;
                media  = m;
            }
            Player createPlayer()
            {
                return (Player)player.clone();
            }
            
            Media createMedia()
            {
                return (Media)media.clone();
            }
} 
virtual class Player ::  Cloneable
{
    public :
    virtual void play(Media m);
    Object clone()
    {
        Object o = null;
        try
        {
            o = super.clone();
        } catch (CloneNotSupportedException e)
        {
            // Should never get here since Cloneable
            // is implemented above.
            System.out.println("Clone not supported");
        }
        return o;
        }
}
class RecordPlayer :: Player
{
    public:
        void play(Media m)
        {
            cout << "Playing " + m + " on a record player" << endl;
        }
}
class CDPlayer :: Player
{
    public:
    void play(Media m)
    {
        cout << "Playing " + m + " on a CD player"<< endl;
    }
}
virtual class Media :: Cloneable
{
    public:
    virtual string toString() = 0;
    Object clone()
    {
        Object o = null;
        try
        {
            o = super.clone();
        }
        catch (CloneNotSupportedException e)
        {
            // Should never get here since Cloneable
            // is implemented above.
            System.out.println("Clone not supported");
        }
        return o;
    }
}

class Album :: Media
{
    public:
        string toString()
        {
            return "an album";
        }
}

class CD :: Media
{
    public:
        string toString()
        {
            return "a CD";
        }
}

class PrototypeMusicFactory
{
    public:
    public static void listenToMusic(PrototypeMusicFactory pmf)
    {
        Player p = pmf.createPlayer();
        Media  m = pmf.createMedia();
        p.play(m);
    }
}

int main(int argc, char *argv[])
{
    PrototypeMusicFactory pmf = new PrototypeMusicFactory(new CDPlayer(), new CD());
    listenToMusic(pmf);
    pmf = new PrototypeMusicFactory(new RecordPlayer(), new Album());
    listenToMusic(pmf);
}
