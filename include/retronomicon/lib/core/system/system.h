
/**
 * @brief The namespace for core system
 */
using namespace std;
namespace retronomicon::lib::core::system{
    class System {
    public:
        virtual ~System() = default;

        virtual void update(float dt, const vector<GameObject>& objects) {}
        virtual void render(const vector<GameObject*>& objects) {}
    };
}