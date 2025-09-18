namespace retronomicon::graphics::renderer {
    class IRenderer {
    public:
        virtual void init() = 0;
        virtual void render() = 0;
        virtual void shutdown() = 0;
        virtual ~IRenderer() = default;
    };
}
