import UIKit

class PreviewCalendarInfoView: UIView {
    
    private let titleLabel: UILabel = {
        let label = UILabel()
        label.text = "Calendar"
        label.font = .systemFont(ofSize: 16, weight: .medium)
        label.textColor = .label
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    private let calendarLabel: UILabel = {
        let label = UILabel()
        label.textColor = .gray
        label.font = .systemFont(ofSize: 16)
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    private let calendarDot: UIView = {
        let view = UIView()
        view.layer.cornerRadius = 6
        view.translatesAutoresizingMaskIntoConstraints = false
        view.widthAnchor.constraint(equalToConstant: 12).isActive = true
        view.heightAnchor.constraint(equalToConstant: 12).isActive = true
        return view
    }()
    
    init(title: String, color: CGColor) {
        super.init(frame: .zero)
        configure(title: title, color: color)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func configure(title: String, color: CGColor) {
        calendarLabel.text = title
        calendarDot.backgroundColor = UIColor(cgColor: color)

        let spacerView = UIView()
        spacerView.setContentHuggingPriority(.defaultLow, for: .horizontal)

        let rightStackView = UIStackView(arrangedSubviews: [calendarDot, calendarLabel])
        rightStackView.axis = .horizontal
        rightStackView.spacing = 6
        rightStackView.alignment = .center
        rightStackView.setContentHuggingPriority(.defaultHigh, for: .horizontal)
        rightStackView.translatesAutoresizingMaskIntoConstraints = false

        let mainStackView = UIStackView(arrangedSubviews: [titleLabel, spacerView, rightStackView])
        mainStackView.axis = .horizontal
        mainStackView.alignment = .center
        mainStackView.translatesAutoresizingMaskIntoConstraints = false

        addSubview(mainStackView)

        NSLayoutConstraint.activate([
            mainStackView.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 16),
            mainStackView.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -16),
            mainStackView.topAnchor.constraint(equalTo: topAnchor, constant: 10),
            mainStackView.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -10)
        ])
    }
}
