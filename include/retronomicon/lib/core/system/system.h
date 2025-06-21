
/**
 * @brief The namespace for core system
 */
namespace retronomicon::lib::core::system{
    class System {
    public:
        virtual ~System() = default;

        virtual void update(float dt, const std::vector<std::shared_ptr<GameObject>>& objects) {}
        virtual void render(const std::vector<std::shared_ptr<GameObject>>& objects) {}
    };
}